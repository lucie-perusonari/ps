import os, os.path, shutil
import requests
import math

problem_tier = ["bronze", "silver", "gold", "platinum", "diamond", "ruby"]
cwd = os.getcwd().replace("\\temp", "") ## 현재 경로 획득. 후 수정

problem_dir = {}

file_count = 0
tier_count = {}
tier_level_count = {}

def init_count():
	for tier in problem_tier:
		tier_count.update({tier:0})
		for i in range(1, 6):
			tier_level_count.update({f"{tier}-{i}":0})
			

## 초기에 저장 파일을 생성하는 함수.
def create_tier_dir():
	for level in range(1, 31):
		tier = problem_tier[int((level-1)/5)]
		tier_level = str(5 - (level-1)%5)

		root_dir = "\\".join([cwd, "tier"])
		tier_dir = "\\".join([cwd, "tier", tier])
		level_dir = "\\".join([cwd, "tier", tier, tier_level])

		if(os.path.exists(root_dir) == False):
			os.mkdir(root_dir)

		if(os.path.exists(tier_dir) == False):
			os.mkdir(tier_dir)

		if(os.path.exists(level_dir) == False):
			os.mkdir(level_dir)


## 레벨과 파일을 이동 시키는 함수.
def transfer(problem_file_dir, level):
	level = int(level)
	global file_count

	tier = problem_tier[math.floor((level-1)/5)]
	tier_level = str(((5 - level) % 5) + 1)
	level_dir = "\\".join([cwd, "tier", tier, tier_level])

	shutil.copy(problem_file_dir, level_dir)
	file_count+=1
	tier_count[tier] +=1
	tier_level_count[f"{tier}-{tier_level}"] +=1
	
## 서버에서 데이터를 가져와서 맵핑해주는 함수.
def get_problem_level(user_id):
	problem_level = {}

	## solved_by:부분에 공백까지도 신경을 써줘야 했음.
	## 또한 한 번에 모든 데이터를 다 가져오지 못함. 페이지를 신경써야 함.
	page = 1
	while(True):
		response = requests.get("https://solved.ac/api/v3/search/problem", params={"direction":"asc", "query": f"solved_by:{user_id}" ,"sort":"solved", "page":{page}}, headers={"x-solvedac-language":"ko"}).json()
		if(len(response["items"]) == 0):
			break

		for problem in response["items"]:
			## 타입을 주의하자.
			problem_level.update({str(problem["problemId"]): str(problem["level"])})
		
		page+=1

	return problem_level

def run(problem_level:dict):

	## walk는 하위의 모든 파일 요소를 가져온다.
	for (path, dir, files) in os.walk(cwd):
		## 그래서 복사한 파일을 다시 참조하는 일이 벌어지니 이렇게 처리 함.
		if(path.count("tier")>0):
			continue

		for filename in files:
			ext = os.path.splitext(filename)[-1]

			## 아이디와 파일 경로를 알게 되었다면, 그 다음 이 정보를 이용해서 레벨을 구하고, 파일을 옮김.
			if (ext ==".cpp" and filename.split('.')[0].isdecimal() == True):
				problem_id = filename.split(".")[0]
				problem_file_dir = "\\".join([path, filename])
				if (problem_id in problem_level):
					level = problem_level[problem_id]
					transfer(problem_file_dir, level)
				else:
					print(level + " is Not Founded")


## 디렉토리를 파일을 생성함.
# create_tier_dir()

## 초기화.
init_count()

# ## 레벨을 구함.
problem_level = get_problem_level("wiiwiwi")

# ## 파일을 순회하며 옮김.
run(problem_level)

print(file_count)
print(tier_count)
print(tier_level_count)
