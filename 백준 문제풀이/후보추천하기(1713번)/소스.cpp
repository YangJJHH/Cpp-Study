#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int N, COUNT;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt","r",stdin);
	cin >> N >> COUNT;
	vector<int> photo;
	vector<int> arr(COUNT);
	vector<int> recommend(100,0); //추천 수
	vector<int> time(100, 0); // 시간 
	for (int i = 0; i < COUNT; i++)
	{
		cin >> arr[i];
	}
	
	for (int i=0; i<COUNT; i++)
	{
		//사진틀에 이미 게시된 사진이라면
		auto it = find(photo.begin(), photo.end(), arr[i]);
		if (it != photo.end())
		{
			recommend[arr[i]]+=1; //추천수 증가
		}
		// 사진틀에 자리가 있다면
		else if (photo.size()<N)
		{
			photo.push_back(arr[i]);
			recommend[arr[i]]+=1; //추천수 증가
		}
		//사진틀이 꽉찬 경우
		else
		{
			int min_r = 1001;
			int index;
			for (int j=0; j<N; j++)
			{
				//추천수가 가장 작은 후보 찾기
				if (recommend[photo[j]] <= min_r)
				{
					if (recommend[photo[j]] == min_r) //작은게 여러개인 경우
					{
						//더 오랜된 후보 찾기
						if (time[photo[j]] > time[photo[index]])
						{
							index = j;
							min_r = recommend[photo[j]];
						}
					}
					else
					{
						min_r = recommend[photo[j]];
						index = j;
					}
				}
			}
			//사진 틀에서 교체
			recommend[photo[index]] = 0;
			time[photo[index]] = 0;
			photo[index] = arr[i];
			recommend[arr[i]] += 1;
		}

		//시간 증가
		for (auto& ele : photo)
		{
			time[ele] += 1;
		}
	}
	sort(photo.begin(),photo.end());
	for (auto& ele : photo)
	{
		cout << ele << " ";
	}
	return 0;
}