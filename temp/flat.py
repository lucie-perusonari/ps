import os, re, shutil
cwd = os.getcwd().replace("\\temp", "") ## 현재 경로 획득. 후 수정

def run():

	for dir in os.listdir(cwd):
		if(re.compile(".*\d{4}-\d{2}-\d{2}.*").match(dir.split("/").pop())):
			for (path, dir, files) in os.walk(cwd + "/" + dir):
				for filename in files:
					ext = filename.split(".")[-1]
					if (ext =="cpp" or ext == "js"):
						shutil.copy(path+"/"+filename, cwd+"/"+"solved")


run()