import os
import json

replayPath = '.'

def isTxtFile(file):
    return os.path.isfile(file) and os.path.splitext(file)[1] == '.txt'

def getfStringFrom(file):
    str = None
    fullPath = os.path.abspath(replayPath)
    filePath = os.path.join(fullPath,file)
    with open(filePath, 'r') as f:
        str = f.read()
    return str

def getJsonObj(str):
    begin = str.find('{')
    end = str.rfind(';')
    if begin == -1 or end == -1:
        return None
    return json.loads(str[begin:end])

for file in os.listdir(replayPath):
    if not isTxtFile(file):
        continue
    str = getfStringFrom(file)
    if str == None:
        continue
    jsonObj = getJsonObj(str)
    if jsonObj == None:
        continue
    #TODO read valid info
    print(jsonObj)
