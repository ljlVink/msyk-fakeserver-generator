#include<bits/stdc++.h>
using namespace std;
char s[1000];
char s1[1000];
char name[1000];
char password[1000];
char hhoo[8]="HHOO";
char sh[100]="stringhash /A:MD5 /S:";
char cmd[100]=">hash.txt";
char Hash[100];
char mod3a[5]="%3A";
char ans[100000],ans1[100000],anss[100000],ans2[100000];
char wget[100]="wget --no-check-certificate -O data.json ";
char ver[100]="&versionCode=28";
int main(int argc,char* argv[]){
    if(argc!=9){
        printf("ERROR\n");
        if(argc==0){
            printf("No Arguments\n");
            printf("Usage:gen.exe acount password mac mac mac mac mac mac\nexample gen.exe Myaccount Mypassword AA AA AA AA AA AA\n");
        }
        else printf("Arguments error\n");
        exit(0);
    }
    sprintf(s,"%s%s%s",argv[1],argv[2],hhoo);
    sprintf(s1,"%s%s%s",sh,s,cmd);
    system(s1);
    freopen("hash.txt","r",stdin);
    scanf("%s",&Hash);
    freopen("link.txt","w",stdout);
    sprintf(ans,"https://padapp.msyk.cn/ws/app/padLogin?userName=%s&auth=%s&macAddress=",argv[1],Hash);
    sprintf(anss,"%s%c%d%s%s%c%d%s%s%c%d%s%s%c%d%s%s%c%d%s%s",argv[3],'%',3,"A",argv[4],'%',3,"A",argv[5],'%',3,"A",argv[6],'%',3,"A",argv[7],'%',3,"A",argv[8]);
    sprintf(ans2,"%s%s%s",ans,anss,ver);
    sprintf(ans1,"%s%c%s%c",wget,'"',ans2,'"');
    system(ans1);
    fclose(stdin);
    fclose(stdout);
    system("del hash.txt");
    system("del link.txt");
    freopen("Vink.py","w",stdout);
    printf("from mitmproxy import ctx,http\nimport json,os\nclass ModifyResponse:\n    def response(self,flow):\n        if flow.request.url.startswith(\"https://padapp.msyk.cn/ws/app/padLogin\"):\n            with open('data.json','rb') as f:\n                res = json.load(f)\n            flow.response.set_text(json.dumps(res))\naddons = [\n    ModifyResponse()\n]\n");
    fclose(stdin);
    fclose(stdout);
    system("mitmdump.exe --script Vink.py -p 8888");
    return 0;
}