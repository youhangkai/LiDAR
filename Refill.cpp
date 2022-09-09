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

//ŷʽ���뺯��
double distance(double x1, double y1, double x2, double y2)
{
	double temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return temp;
}

double Rth = 1.5;
int Num = 1;
double x,y,z;
int intensity,i;

//������
int main()
{
	ifstream in("F:\\���ϵĳ����ں�����\\��ľ����ȡ\\merge_downsampling0.9�������ϡ1015.txt");//����

	//while(in>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z>>PointCloudData[Num].intensity)
	while(in>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z)
	{
		Num++;
	}//��������
	Num--;
	
	cout<<"step1 finished"<<endl;
	
	int PointCloudNum = Num;
	
	freopen("F:\\���ϵĳ����ں�����\\��ľ����ȡ\\merge_downsampling0.9�������ϡ1015+�����1.5.txt","w",stdout); 
	freopen("F:\\���ϵĳ����ں�����\\merged.txt","r",stdin);
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
	
	fclose(stdin);//�ر��ļ�
	fclose(stdout);//�ر��ļ�


return 0;
}
