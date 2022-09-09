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

PointCloudStruct PointCloudData[1000000];

//欧式距离函数
double distance(double x1, double y1, double x2, double y2)
{
	double temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return temp;
}

double Rth = 1.5;
int Num = 1;
double x,y,z;
int intensity,i;

//主函数
int main()
{
	ifstream in("F:\\王迪的城市融合数据\\树木点提取\\merge_downsampling0.9特征点抽稀1015.txt");//输入

	//while(in>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z>>PointCloudData[Num].intensity)
	while(in>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z)
	{
		Num++;
	}//读入数据
	Num--;
	
	cout<<"step1 finished"<<endl;
	
	int PointCloudNum = Num;
	
	freopen("F:\\王迪的城市融合数据\\树木点提取\\merge_downsampling0.9特征点抽稀1015+地面点1.5.txt","w",stdout); 
	freopen("F:\\王迪的城市融合数据\\merged.txt","r",stdin);
	while(cin>>x>>y>>z)
	{
		for(i = 1; i<= PointCloudNum; i++)
		{
			double dis = distance(PointCloudData[i].x,PointCloudData[i].y,x,y);
			if(dis <= Rth)
			{
				printf(" %lf  %lf  %lf",x,y,z);
				cout<<endl;
				break;
			}
		}
	} 
	
	fclose(stdin);//关闭文件
	fclose(stdout);//关闭文件


return 0;
}
