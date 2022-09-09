#include<bits/stdc++.h>

using namespace std; 

typedef struct PointCloudStruct
{
	double x;
	double y;
	double z;
//	int r;
//	int g;
//	int b;
//	int intensity;
//	int returnnumber;
//	double GPStime; 
	int otherpoint;
} PointCloudStruct;

PointCloudStruct PointCloudData[10000000];

//欧式距离函数
double distance(double x1, double y1, double x2, double y2)
{
	double temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return temp;
}

double Rth = 3.0;
int Oth = 15;
int Num = 1;

//主函数
int main()
{
	freopen("F:\\王迪的城市融合数据\\树木点提取\\merge_downsampling0.9特征点抽稀10.txt","r",stdin); //输入重定向，输入数据将从txt文件中读取
	

	//while(cin>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z>>PointCloudData[Num].intensity)
	while(cin>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z)
	{
		Num++;
	}//读入数据
	Num--;
	
	int PointCloudNum = Num;

	for(int i = 1; i<= PointCloudNum; i++)
	{
		for(int k = 1 ; k <= PointCloudNum; k++)
		{
			double dis = distance(PointCloudData[i].x,PointCloudData[i].y,PointCloudData[k].x,PointCloudData[k].y);
			if((k != i) && (dis <= Rth)) PointCloudData[i].otherpoint++;
		}
		
		//确认程序正在运行 
		if(i == 100) cout<<"100"<<endl; 
		//进度条百分比 
		if(i == int(PointCloudNum* 0.1)) cout<<"10%"<<endl; 
		if(i == int(PointCloudNum* 0.2)) cout<<"20%"<<endl; 
		if(i == int(PointCloudNum* 0.3)) cout<<"30%"<<endl; 
		if(i == int(PointCloudNum* 0.4)) cout<<"40%"<<endl; 
		if(i == int(PointCloudNum* 0.5)) cout<<"50%"<<endl; 
		if(i == int(PointCloudNum* 0.6)) cout<<"60%"<<endl; 
		if(i == int(PointCloudNum* 0.7)) cout<<"70%"<<endl; 
		if(i == int(PointCloudNum* 0.8)) cout<<"80%"<<endl; 
		if(i == int(PointCloudNum* 0.9)) cout<<"90%"<<endl; 
		if(i == int(PointCloudNum* 1.0)) cout<<"100%"<<endl; 
	}
	
	freopen("F:\\王迪的城市融合数据\\树木点提取\\merge_downsampling0.9特征点抽稀1015.txt","w",stdout); //输出重定向，输出数据将保存在txt文件中 416
	
	for(int i = 1; i<= PointCloudNum; i++)
	{
		if(PointCloudData[i].otherpoint >=  Oth)
		{
		//printf("%lf  %lf  %lf  %d",PointCloudData[i].x,PointCloudData[i].y,PointCloudData[i].z,PointCloudData[i].intensity);
		printf("%lf  %lf  %lf",PointCloudData[i].x,PointCloudData[i].y,PointCloudData[i].z);
		cout<<endl;
		}
		else continue;
	}

	fclose(stdin);//关闭文件
	fclose(stdout);//关闭文件


return 0;
}
