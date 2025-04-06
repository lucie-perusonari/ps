import os, os.path, shutil

## 현재 경로 획득.
cwd = os.getcwd()

cwd = cwd.replace("\\temp", "")

## 이렇게 구현할 필요가 없이 그냥 ps아래의 cpp파일들을 싹다 가져오는 편이 훨씬 깔끔할 듯.
list = os.listdir("../")
for file in list:
    file = os.path.join(cwd, file)
    print(file)

