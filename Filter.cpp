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

//ŷʽ���뺯��
double distance(double x1, double y1, double x2, double y2)
{
	double temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return temp;
}

double Rth = 3.0;
int Oth = 15;
int Num = 1;

//������
int main()
{
	freopen("F:\\���ϵĳ����ں�����\\��ľ����ȡ\\merge_downsampling0.9�������ϡ10.txt","r",stdin); //�����ض����������ݽ���txt�ļ��ж�ȡ
	

	//while(cin>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z>>PointCloudData[Num].intensity)
	while(cin>>PointCloudData[Num].x>>PointCloudData[Num].y>>PointCloudData[Num].z)
	{
		Num++;
	}//��������
	Num--;
	
	int PointCloudNum = Num;

	for(int i = 1; i<= PointCloudNum; i++)
	{
		for(int k = 1 ; k <= PointCloudNum; k++)
		{
			double dis = distance(PointCloudData[i].x,PointCloudData[i].y,PointCloudData[k].x,PointCloudData[k].y);
			if((k != i) && (dis <= Rth)) PointCloudData[i].otherpoint++;
		}
		
		//ȷ�ϳ����������� 
		if(i == 100) cout<<"100"<<endl; 
		//�������ٷֱ� 
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
	
	freopen("F:\\���ϵĳ����ں�����\\��ľ����ȡ\\merge_downsampling0.9�������ϡ1015.txt","w",stdout); //����ض���������ݽ�������txt�ļ��� 416
	
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

	fclose(stdin);//�ر��ļ�
	fclose(stdout);//�ر��ļ�


return 0;
}
