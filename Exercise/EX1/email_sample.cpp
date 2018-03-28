// A sample code for exercise Email
// only partial functions are implemented
#include <bits/stdc++.h>
using namespace std;
int n;

struct Email {
    char name[100];
    char domain[100];
};

// return true if p before q
bool cmpd(Email &p,Email &q){
    return (strcmp(p.domain,q.domain)<0 ) ;
}


void sol() {
  Email addr[100];
  char line[210];
  char alpha[10]=".@_ "; // valid characters
  int myint,j,k,x,y;
  j=0;gets(line);
  for (int i=0;i<n;i++) {
    fgets(line,200,stdin);
    line[strlen(line)-1]='\0'; // overwrite the end of line
    char *s;
    // check invalid character
    for (s=line;*s;s++) {
        if (!isalpha(*s) && !isdigit(*s) && strchr(alpha,*s)==NULL)
            break;
    }
    if (*s) {
        cout<<"invalid character "<<*s<<endl;
        continue;
    }

    char *p=strchr(line,'@'); // find the first @
    if (p==NULL) {
        cout<<line<< " is not a valid address, lacking of @"<<endl;
        continue;
    }
    // break line into two string separated by found @
    strncpy(addr[j].name,line,p-line);
    addr[j].name[p-line]='\0';
    strcpy(addr[j].domain,p+1);
    if (strchr(addr[j].domain,'@')!=NULL ) {
        cout<<line<< " too many @"<<endl;
        continue;
    }
    j++;
  }
  for (int i=0;i<j;i++) {
    printf("[%s]:[%s]\n",addr[i].name,addr[i].domain);
  }
  sort(addr,addr+j,cmpd);
  cout<<"sort by domain"<<endl;
  for (int i=0;i<j;i++) {
    printf("[%s]:[%s]\n",addr[i].name,addr[i].domain);
  }
  return;
}


int main ()
{
    freopen("email.in","r",stdin);
    while (1) {
        cin>>n;
        if (n==0) break;
        sol();
    }
    return 0;
}
