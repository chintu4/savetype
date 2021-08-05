import os
import sys
import pwd
def get_username():
    i=pwd.getpwuid(os.getuid())
    list(i)
    return i[0]

file=f"/home/{get_username()}/Documents/c.txt"
def search(s):
    f=open(file,"r")
    re=f.read().split(",")
    v=[]
    for i in range(len(re)):
        v.append(re[i].split(":"))
        v[i][0].replace("\n","")
        #if v[i][0]=='""\n':
            #v.pop(i)
    f.close()
    for i in range(len(v)):
        if v[i][0]==s:
            if v[i][1]==None:
                print("not found in c.txt")
            return (v[i][1]).strip('"')
def writeFile(key,value):
    f=open(file,"a")
    f.write(',%s:"%s"'%(key,value));

if __name__=="__main__":
    try:
        arg=sys.argv[1]
        if arg=="w":
            writeFile(sys.argv[2],sys.argv[3])
        else:
            os.system(search(arg))
    except IndexError:
        print("\U0001f600 argv not passed")

