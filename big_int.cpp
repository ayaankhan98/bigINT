
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class BigInteger
{
public:
string str;
int sign;

  BigInteger()
  {
    sign=0;
    str="0";
  }
  BigInteger(string s)
  { 
    if(s[0]=='-')
     { sign=1;
      str=s.substr(1);}
      else{
    sign=0;str=s;}
  }
  
  BigInteger(ll s)
  { sign=0;
    if(s<0)	
     { sign=1;}
   str=to_string(s);
  }

friend bool operator< (BigInteger  , BigInteger  );
friend bool operator> (BigInteger  , BigInteger  );
friend bool operator<= (BigInteger  , BigInteger  );
friend bool operator>= (BigInteger  , BigInteger  );
friend bool operator== (BigInteger  , BigInteger  );
friend bool operator!= (BigInteger  , BigInteger  );
friend BigInteger operator+ (BigInteger  , BigInteger  );
friend BigInteger operator- (BigInteger  , BigInteger  );
friend BigInteger operator* (BigInteger  , BigInteger  );
friend BigInteger operator/ (BigInteger  , BigInteger  );
friend BigInteger operator% (BigInteger  , BigInteger  );
friend ostream & operator<< (ostream &out, const BigInteger &a);





};

bool operator< (BigInteger  a, BigInteger  b) {
  string str1=a.str;
  string str2=b.str;
  if (a.sign != b.sign){return a.sign>b.sign;}
    else if(str1.size()!=str2.size()){//cout<<(a.size>b.size);
    return str1.size()<str2.size();}
  else
  { 
    for(int i=0;i<str1.size();i++)
    {
           if(str1[i] != str2[i])
            {//cout<<(temp->data > temp1->data);
              return (str1[i]-'0')< (str2[i]-'0');}
              }
  }
  return false;
  }

  
  bool operator== (BigInteger  a, BigInteger  b) {
     string str1=a.str;
  string str2=b.str;
  if (a.sign != b.sign){return false;}
  else if(str1.size()!=str2.size()){
    return false;}
  else
  { 
    for(int i=0;i<str1.size();i++)
    {
           if(str1[i] != str2[i])
            {
              return false;}
           
    }
  }
  return true;
  }
  bool operator!= (BigInteger  a, BigInteger  b) {
  return !(a==b);
  }
  bool operator<= (BigInteger  a, BigInteger  b) {
  return (a<b || a==b);
  }
  bool operator> (BigInteger  a, BigInteger  b) {
  return !(a<=b);
  }
  bool operator>= (BigInteger  a, BigInteger  b) {
  return !(a<b);
  }

BigInteger operator+ (BigInteger  a, BigInteger  b) {
        BigInteger ans;
        if(a.sign==1 && b.sign==1){ a.sign=0; b.sign=0; ans=a+b;  ans.sign=1; return ans; }
       else if(a.sign ==1){ a.sign=0;// cout<< "b-a"<<endl;
        return b-a;
     }
   else if(b.sign ==1){ b.sign=0;//cout<< "a-b"<<endl;
    return a-b;
 }
      
          int carry=0;
          string str1=a.str;
          string str2=b.str;
          string result="";
          //int l=max(str1.size(),str2.size());
          int i=str1.size()-1;
          int j=str2.size()-1;
         for(;i>=0 || j>=0;)
          {
            
             if (i>=0) {carry += str1[i]-'0'; }
          if (j>=0) {carry += str2[j]-'0'; }
              //string s=to_string(carry%10);
              result.insert(0,1,(carry%10)+'0');
              carry =carry/10;
              //cout<<carry<<endl;
              i--;
              j--;
            }
            if(carry)

            { //string s=to_string(carry);
              result.insert(0 ,1,carry+'0');
                    }
          ans.str=result;
          //cout<<ans.last;
        //cout<<endl;
           return ans;
         }
            
              

BigInteger operator- (BigInteger  a, BigInteger  b){
       BigInteger ans;
        if(a.sign==1 && b.sign==1){a.sign=0;b.sign=0; //cout<< "b-a"<<endl;
        return b-a; }
       else if(a.sign ==1){ a.sign=0;  ans=b+a; ans.sign=1;//cout<< "-(b+a)"<<endl; 
       return ans; }
      else if(b.sign ==1){ b.sign=0;//cout<< "b+a"<<endl; 
      return a+b;}
        else if(a<b){//cout<<"- b-a"; 
        ans=b-a; ans.sign=1; return ans;}
          
          
          int carry=0;
         string str1=a.str;
          string str2=b.str;
          string result="";
         int i=str1.size()-1;
          int j=str2.size()-1;
         for(;i>=0 || j>=0;)
          {
            
             if (i>=0)  {carry += str1[i]-'0';   }
           if (j>=0)  {carry -= str2[j]-'0';  }
          //cout<<carry<<endl;
                 if(carry<0)
            { //string s=to_string((carry+10));
             result.insert(0,1,(carry+10)+'0');
             //cout<<carry+10<<endl;
              carry=-1;
              //cout<<carry<<endl;
                 }
              
              else{ //string s=to_string((carry));
                result.insert(0,1,carry+'0');
                //ans.number[i]=(carry);
             //  cout<<carry<<endl;
              carry =0;
              
            }
            i--;j--;
            }
            while(result[0]=='0' && result.length()!=1) 
    result.erase(0,1);
             ans.str=result;
            return ans;
        }

      
BigInteger operator* (BigInteger  a, BigInteger  b) {
        //string s="";
        
     //   if(a.sign==1 && b.sign==1){ }
     //  else if(a.sign ==1){ ans.sign=1;}
     // else if(b.sign ==1){ ans.sign=1;}
     string str1=a.str;
          string str2=b.str;
          
            BigInteger ans;
      int first;
          int i,j;
          int carry;
          
          int l1=str1.size();
          int l2=str2.size();
          int number[(l1+l2)]={0};
          for(i=l1-1;i>=0;i--) {
         carry = 0;
         int n=str1[i]-'0';
        for (j=l2-1;j>=0;j--) {
            int s = number[i+j+1] + carry + (n)*(str2[j]-'0');
            //cout<<s<<endl;
            number[i+j+1] = s%10;
            carry = s/10;
               //cout<<s<<endl;
          }
          first=i+j+2;
          if(carry)
          {
            number[i+j+1]+=carry;
            first--;
          }
    }  
          string s = ""; 
      int i1=first;
    while (i1<(l1+l2)) 
       { 
        s +=(number[i1++]+'0'); 
       } ans.str=s;
           return ans;
}

   /*   BigInteger operator* (BigInteger  a, BigInteger  b) {
        //string s="";
         
       // if(a.sign==1 && b.sign==1){ }
       //else if(a.sign ==1){ ans.sign=1;}
      //else if(b.sign ==1){ ans.sign=1;}
     string str1=a.str;
          string str2=b.str;
          int l2=str2.size();
          if(l2<10)
          {
            BigInteger ans;
      int first;
          int i,j;
          int carry;
          
          int l1=str1.size();
          
          int number[(l1+l2)]={0};
          for(i=l1-1;i>=0;i--) {
         carry = 0;
         int n=str1[i]-'0';
        for (j=l2-1;j>=0;j--) {
            int s = number[i+j+1] + carry + (n)*(str2[j]-'0');
            //cout<<s<<endl;
            number[i+j+1] = s%10;
            carry = s/10;
               //cout<<s<<endl;
          }
          first=i+j+2;
          if(carry)
          {
            number[i+j+1]+=carry;
            first--;
          }
    }  
          string s = ""; 
      int i1=first;
    while (i1<(l1+l2)) 
       { 
        s +=(number[i1++]+'0'); 
       } ans.str=s;
           return ans;
}
else
{BigInteger res("0");
  string s[10];
s[0]="0";
s[1]=str1;

int l=str1.size();
for(int i=2;i<=9;i++)
{ string result;
  int mul=0;
for (int j=l-1;j>=0;j--) {
            mul += i*(str1[j]-'0');
            //cout<<s<<endl;
             result.insert(0,1,((mul%10)+'0'));
              mul=mul/10;
               //cout<<s<<endl;
          }
          if(mul)
            result.insert(0,1,(mul+'0'));
          s[i]=result;
          //cout<<s[i]<<endl;
}
int j=0;

for(int i=l2-1;i>=0;i--)
{
  string temp=s[str2[i]-'0'];
  //cout<<temp<<" ";
  temp.insert(temp.end(),l2-1-i,'0');
  //cout<<res<<" ";
  //BigInteger temp1(temp);
  res=res+temp;
  //cout<<temp1<<" "<<res<<endl;
j++;
}
return res;}

            
              }*/


/*BigInteger operator* (BigInteger  a, BigInteger  b) {

BigInteger res("0");
string str1=a.str;
string str2=b.str;
string s[10];
s[0]="0";
s[1]=str1;

int l=str1.size()-1;
for(int i=2;i<=9;i++)
{ string result;
  int mul=0;
for (int j=l;j>=0;j--) {
            mul += i*(str1[j]-'0');
            //cout<<s<<endl;
             result.insert(0,1,((mul%10)+'0'));
              mul=mul/10;
               //cout<<s<<endl;
          }
          if(mul)
            result.insert(0,1,(mul+'0'));
          s[i]=result;
          //cout<<s[i]<<endl;
}
int j=0;
for(int i=str2.size()-1;i>=0;i--)
{
  string temp=s[str2[i]-'0'];
  //cout<<temp<<" ";
  temp=temp.append(j,'0');
  //cout<<res<<" ";
  //BigInteger temp1(temp);
  res=res+temp;
  //cout<<temp1<<" "<<res<<endl;
j++;
}
return res;
}*/

/*
BigInteger operator/ (BigInteger  a, BigInteger  b) {
        //string s="";
        BigInteger div("0");
        if(a.sign==1 && b.sign==1){ }
       else if(a.sign ==1){ div.sign=1;}
      else if(b.sign ==1){ div.sign=1;}
     //if(b>a){return b/a;} 
       
       //BigInteger c=a;
       // cout<<c<<" "<<b<<" "<<endl;
       while( a >= b )
       {
        //bool bl = c>=b ;
          a=a-b;
          div=div+1;
          cout<<a<<" "<<b<<endl;
        }

           return div;
            
              }
*/

BigInteger operator% (BigInteger  a, BigInteger  b) {
        //string s="";

        BigInteger mod("0");
      string str1=b.str;
      int si=str1.size();
      BigInteger temp("0");
      int diff= a.str.size()-si;
      while(diff>2)
      { 
        string str (diff,'1');
      BigInteger b1(str);
      temp=b*b1;
        a=a-temp;
       diff= a.str.size()-si;
       }
   while(a<0)
        {
          a=a+b;
        }
while( a >= b )
       {
        //bool bl = c>=b ;
          a=a-b;
         //cout<<a<<" "<<b<<endl;
        }

           return a;
              }

ostream & operator<< (ostream &out, const BigInteger &a) {
      string s=a.str;
      
      if(a.sign==1)
        {
         
          s='-'+s;
        }out<<s;
    return out;
}
BigInteger  factorial(int a)
   { BigInteger i("2");
   BigInteger ans("1");
  // cout<<a;
   for(;i<=a;i=i+1)
   {
    
      ans=ans*i;
      //cout<<ans<<endl; 
   }
    
return ans;

   }
BigInteger expo(BigInteger a, ll b){
  BigInteger e("1");
  //string s=a.str;
  //BigInteger a1=a*a;
 //cout<<e<<endl;
    if(b==0)
    return 1;
  else if(b==1)
    return a;
  else if(b%2==0)
    {e=expo(a,b/2);
      return e*e;}
  else
    {int n=b-1;
    e=expo(a,n/2);
    return a*e*e;}
}
/*
BigInteger gcd(BigInteger a,BigInteger b)
{
   if (a.str == "0") 
       return b; 
    if (b.str == "0") 
       return a; 
    if (a == b) 
        return a; 
   if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}
*/

BigInteger gcd(BigInteger a,BigInteger b)
{
  if(a<b) return gcd(b,a);
   if (b == 0) 
       return a; 
   
a=a%b;
 return gcd(b,a); 
   
}
 

int main()
{

 int Q,c;
    string x,y;
    int n;
    cin>>Q;
    while (Q--){      
 
 cin>>c;

 switch (c)
 {

case 1: cin>>x;
         cin>>n;
         //BigInteger A(x);
         cout<<expo(x,n)<<endl;
         break;
 case 2: cin>>x;
         cin>>y;
         //BigInteger A(x);
         //BigInteger B(y);
         cout<<gcd(x,y)<<endl;
         break;
 
 case 3: cin>>n;
         //BigInteger A(x);
         cout<<factorial(n)<<endl;
         break;

default:
     break;
 }
}
//cout<<"\nTime"<<1000*clock()/CLOCKS_PER_SEC<<"ms";
 return 0;
}
