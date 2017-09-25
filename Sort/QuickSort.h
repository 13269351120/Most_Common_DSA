#pragma once

#include <vector>

size_t partition(std::vector<int> &v, size_t lo, size_t hi);

void quickSort(std::vector<int> &v, size_t beg, size_t end)
{
	if (end - beg < 2) return;

	size_t p = partition(v, beg, end - 1);

	quickSort(v, beg, p);
	quickSort(v, p + 1, end);
}

//���ǻ����汾�Ŀ��ٻ����㷨���ð汾����һ�����⣺����������Ԫ�ؾ��ظ���ʱ��ʱ�临�ӶȻἱ������������O(n^2)
//��һ���汾���㷨���Խ��������⣬����ÿ�λ��ֿ��ܻ��������εĸ�ֵ��������������ʱ�临�ӶȲ���Ӱ�죬�������˻����
//�£�ʱ�临�ӶȻ�ﵽ��õ�O(logn);    ע���ڶ����汾��Ӿ���ŵĲ��ȶ��ԣ�
#ifdef EDITION_A

size_t partition(std::vector<int> &v, size_t lo, size_t hi)
{
	using std::swap;
	swap(v[lo], v[lo + rand() % (hi - lo + 1)]);
	int pivot = v[lo];
	while (lo < hi)
	{
		while (lo < hi && pivot <= v[hi]) --hi;
		v[lo] = v[hi];
		while (lo < hi && v[lo] <= pivot) ++lo;
		v[hi] = v[lo];
	}
	v[lo] = pivot;
	return lo;
}

#else

size_t partition(std::vector<int> &v, size_t lo, size_t hi)
{
	using std::swap;
	swap(v[lo], v[lo + rand() % (hi - lo + 1)]);
	int pivot = v[lo];

	while (lo < hi)
	{
		while (lo < hi)
		{
			if (pivot < v[hi]) --hi;
			else
			{
				v[lo++] = v[hi];
				break;
			}
		}
		while (lo < hi)
		{
			if (v[lo] < pivot) ++lo;
			else
			{
				v[hi--] = v[lo];
				break;
			}
		}
	}
	v[lo] = pivot;
	return lo;
}

#endif