#include <iostream>
using namespace std;

void DigitalClockIntToStr(int sec , char time[11])
{
//two variables to calculate
//minutes and hours .
int minn=0,hor=0;

//condition if user input number
//of seconds out of range .
if ( sec>=86400 || sec<0 ){
    time[0]='i';
    time[1]='n';
    time[2]='v';
    time[3]='a';
    time[4]='l';
    time[5]='i';
    time[6]='d';
    time[7]='\0';
}

else{
//calculating number of seconds
//that should appear on clock .
    while (sec>=60){
        minn++;
        sec-=60;
    }
//calculating number of minutes
//that should appear on clock .
    while (minn>=60){
        hor++;
        minn-=60;
    }
//condition to know if we are
//at day or at night .
    if(hor>12){
        time[8]='p';
        hor-=12;
    }
    else{
        time[8]='a';
    }

//hours 0 mean its 12 now .
    if(hor==0){
        hor=12;
    }

//setting values to my char array .
    time[0]=(hor/10)+48;
    time[1]=(hor%10)+48;
    time[2]=':';
    time[3]=(minn/10)+48;
    time[4]=(minn%10)+48;
    time[5]=':';
    time[6]=(sec/10)+48;
    time[7]=(sec%10)+48;
    time[9]='m';

}
}


DigitalClockStrToInt(const string time)
{
//variables for time .
int sec=0,hor=0,minn=0,flag=0;

//condition to know if we are
//at day or at night .
if(time[8]=='a'){
    flag=1;
}

//condition if hours contain two digits .
if(time[0]=='1'){
    hor=(time[1]-48)+10;
}

//calculations .
minn=(time[3]-48)*10;
minn=minn+time[4]-48;
sec=(time[6]-48)*10;
sec=sec+time[7]-48;

//condition to handle hours
//if we are at day or at night .
if(hor==12){
    hor=0;
    if(flag==0){
        sec+=43200;
    }
}

return (hor*60*60)+(minn*60)+sec;
}

int main()
{
cout<<"Enter number of seconds that you want to convert it to time "<<endl;
int a;cin>>a;
char time[11];
DigitalClockIntToStr(a,time);
cout<<time<<endl;
cout<<endl<<"Enter time that you want to convert it to seconds in format like (12:00:00am) "<<endl;
string b;cin>>b;
cout<<DigitalClockStrToInt(b);
return 0;
}
