
#include<cstring>
#include<algorithm>
#include<set>
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
#define NUM 2000
char y[4]= {
	'*','+','-','#'
};
set<string> res;
char str[10];
char temp[40];
int n,kase=1;
 
void print(char temp[]) {
	int l=strlen(temp);
	char temp1[10];
	int k=0;
 
	for(int i=0; temp[i]!='='; i++) {
		if(temp[i]!='#')
			temp1[k++]=temp[i];
	}
	temp1[k++]='=';
	temp1[k++]='\0';
	if(res.count(temp1)==0)
		res.insert(temp1);
}
 
bool check(char temp[]) {
	int a=0,b;
	if(temp[0]=='0'&&temp[1]=='#'&&isdigit(temp[2]))
		return false;
	int l=strlen(temp);
	for(int i=2; i<l-2; i++) {
		if((temp[i-1]=='+'||temp[i-1]=='-'||temp[i-1]=='*')&&
		        (temp[i]=='0')&&(temp[i+1]=='#')&&
		        (isdigit(temp[i+2])))
			return false;
	}
	return true;
}
int compute(char temp[]) {
	int b[10];
	char c[10];
	int k=0,l=0;
	int sum=0;
 
 
	for(int i=0; i<strlen(temp)-1; i++) { // NOT =
		if(isdigit(temp[i])) {
 
			b[k++]=temp[i]-48;
		} else if(temp[i]=='#') {
 
			b[k-1]=b[k-1]*10+temp[i+1]-48;
			i++;
		} else {
			c[l++]=temp[i];
		}
	}
 
	for(int i=0; i<l; i++) {
		if(c[i]=='*') {
			b[i+1]=b[i]*b[i+1];
 
			for(int j=i; j<l-1; j++)
				c[j]=c[j+1];
			for(int j=i; j<k-1; j++)
				b[j]=b[j+1];
			i--;
			l--;
			k--;
		}
	}
 
	sum=b[0];
	for(int i=0; i<l; i++) {
 
		switch(c[i]) { 
			case '+':
				sum=sum+b[i+1];
				break;
			case '-':
				sum-=b[i+1];
				break;
		}
	}
	return sum;   
}
void dfs(int d,int c) {
	if(temp[d]=='=') return;//finished
 
	int k=strlen(temp);
	temp[d]=y[c];
	/*
	cout<<d<<endl;
	for(int i=0;i<strlen(temp);i++)
	cout<<temp[i];
	cout<<endl;
	cout<<check(temp)<<":"<<compute(temp)<<endl;*/
	if(check(temp)&&compute(temp)==NUM) {
		print(temp);
	}
	for(int i=0; i<4; i++) {
		dfs(d+2,i);
	}
 
}
 
void process() {
	memcpy(temp,str,sizeof(char)*n);
	n=strlen(str);
	res.clear();
	int k=0;
	int i;
	for(i=0; i<strlen(str)-2; i++) {
		temp[k++]=str[i];
		temp[k++]='#';
	}
	temp[k++]=str[i++];
	temp[k++]=str[i++];
 
 
	for(int i=0; i<4; i++) {
		dfs(1,i);
	}
	cout<<"Problem "<<kase++<<endl;
	if(res.size()>0) {
		set<string>::iterator it;
		for(it=res.begin(); it!=res.end(); it++)
			cout<<"  "<<*it<<endl;
	} else {
		cout<<"  IMPOSSIBLE"<<endl;
	}
 
 
}
 
int main() {
	do {
		gets(str);
		process();
	} while(!(strlen(str)==1&&str[0]=='='));
}