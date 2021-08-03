#include <bits/stdc++.h>
using namespace std;
  int Min,Max;
    string getMax()
    {
        long int num=2;
        for(int i=1;i<=30;++i)
            num*=2;
        --num;
        Max=num;
        Min=(num+1)*(-1);
        string limit="";
        while(num!=0){
            limit=(char)(num%10+'0') +limit;
            num/=10;
        }
        return limit;
    }
    
    string getNum(int index,string s)
    {
        string num="";
        while(s[index]>='0'&&s[index]<='9'&&index<s.size()){
            num+=s[index];
            ++index;
        }
        return num;
    }
    int render(string s)
    {
        long int i=0,num=0;
        while(i<s.size()){
            num=num*10+s[i]-'0';
            ++i;
        }
        return num;
    }
 
    string fixNum(string s){
        int i=0;
        while(s[i]=='0'&&i<s.size()){
            ++i;
        }
        string d="";
        for(i;i<s.size();++i)
            d+=s[i];
        return d;
    }
    int myAtoi(string s) {
        int i=0,dau=-1;
        string limitMax=getMax();
        string limitMin=limitMax;
        limitMin[limitMin.size()-1]++;
        while(s[i]==' '){
            ++i;
        }
        if(s[i]>'9'&&s[i]!='-'&&s[i]!='+')
            return 0;
            
        if(s[i]=='-'){
            ++i;
            string num=getNum(i,s);
            if(num=="0") return 0;
            num=fixNum(num);
            if(num=="") return 0;
            if(num.size()>limitMin.size()) return Min;
            else if(num.size()<limitMin.size()) return (-1)*render(num);
            else if(num.size()==limitMin.size()){
                if(num==limitMin) return Min;
                if(num<=limitMin) return (-1)*render(num);
                else return Min;
            }
            
        }
        
        else{
            if(s[i]=='+')++i;
            string num=getNum(i,s);
            if(num=="0") return 0;     
            num=fixNum(num);
            if(num=="") return 0;
             if(num.size()>limitMax.size()) return Max;
            else if(num.size()<limitMax.size()) return render(num);
            else if(num.size()==limitMax.size()){
                if(num<=limitMax) return render(num);
                else return Max;
            }
        }
        return 0;
    }
int main() {
	string s;
	getline(cin,s);
	cout<<myAtoi(s);
	return 0;
}
