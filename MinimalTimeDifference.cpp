#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
int StringToInt(string x)
{
	stringstream s;
	int pom;
	s<<x;
	s>>pom;
	s.clear();
	return pom;
}
unsigned int ToMinutes(string time_HH_MM)
{
	int i,minuty=0,pom;
	string pomocnicza,pom1;
	if(time_HH_MM[1]==':')
	{
		minuty+=StringToInt(time_HH_MM)*60;
		pomocnicza+=time_HH_MM[2];
		pomocnicza+=time_HH_MM[3];
		minuty+=StringToInt(pomocnicza);
	}
	else
	{
		pomocnicza+=time_HH_MM[0];
		pomocnicza+=time_HH_MM[1];
		minuty+=StringToInt(pomocnicza)*60;
		pom1+=time_HH_MM[3];
		pom1+=time_HH_MM[4];
		minuty+=StringToInt(pom1);
	}
	return minuty;
}
int Min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int AbsoluteValue(int x)
{
	if(x>=0)
	{
		return x;
	}
	else
	{
		return x*(-1);
	}
}
unsigned int MinimalTimeDifference(int minutes1, int minutes2)
{
	int min;
	if(minutes1<minutes2 and minutes1<720 and minutes2>720)
	{
		int pom1=minutes2-minutes1,pom2=minutes1-minutes2+1440;
		min=Min(pom1,pom2);
		return min;
		
	}
	else if(minutes2<minutes1 and minutes2<720 and minutes1>720)
	{
		int pom1=minutes1-minutes2,pom2=minutes2-minutes1+1440;
		min=Min(pom1,pom2);
		return min;
	}
	else
		return AbsoluteValue(minutes1-minutes2); 
}
int main(void)
{
	int roznica,n,i=0,minimal=0;
	cout<<"Podaj ile razy wpiszesz godzine"<<endl;
	cin>>n;
	int tab_minut[n];
	string tab[n];
	while(i<n)
	{
		cout<<"Podaj godzine w formacie HH:MM"<<endl;
		cin>>tab[i];
		i++;
	}
	i=0;
	while(i<n)
	{
		tab_minut[i]=ToMinutes(tab[i]);
		i++;
	}
	minimal=MinimalTimeDifference(tab_minut[0],tab_minut[1]);
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			roznica=MinimalTimeDifference(tab_minut[i],tab_minut[j]);
			if(roznica<minimal)
			{
				swap(roznica,minimal);
			}
		}
	}
	cout<<"Najmniejsza roznica to "<<minimal;
	return 0;	
}
