#include <cstring>
template <class type> class vector
{
private: 
	type* values;
	long long malloc_nums,now;
public:
	vector()
	{
		now=0;
		malloc_nums=0;
		values=NULL;
		malloc_a();
	}
	bool push_back(type value)
	{
		now++;
		if(!malloc_a())return false;
		values[now]=value;
		return true;
	}
	type get_back()
	{
		return values[now--];
	}
	bool pop_back()
	{
		if(!malloc_a())return false;
		if(!now==0)return false;
		now--;
		return true;
	}
	bool malloc_a(){		//auto malloc
		if(malloc_nums<=now+20)
		{	
			type *last=values;
			if(!(values=(type *)malloc(malloc_nums+30)))return false;
			else {
				for(int i=0;i<malloc_nums;i++)
				{
					values[i]=last[i];
				}
				malloc_nums+=30;
				if(last)
					free(last);
				return true;
			}
		}
		if(malloc_nums>=now+40)
		{
			type *last=values;
			if(!(values=(type *)malloc(malloc_nums-40)))return false;
			else {
				if(now-40<5)return true;
				malloc_nums-=40;
				for(int i=0;i<malloc_nums;i++)
				{
					values[i]=last[i];
				}
				if(last)
					free(last);
				return true;
			}
		}
		return true;
	}
	~vector()
	{
		if(values)
			free(values);
	}
};
/*
#include <iostream>
using namespace std;
int main(){
	int num=3;
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(8);
	cout<<vec.get_back()<<"    "<<vec.pop_back(),vec.get_back();
	cin>>num;
}*/