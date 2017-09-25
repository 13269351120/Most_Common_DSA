#pragma once

#include <vector>

void mergeSort(std::vector<int> &v, size_t beg, size_t end);

void merge(std::vector<int> &v, size_t beg, size_t mid, size_t end);

void mergeSort(std::vector<int> &v, size_t beg, size_t end)
{
	if (end - beg < 2) return;

	size_t mid = (beg + end) >> 1;

	mergeSort(v, beg, mid);
	mergeSort(v, mid, end);
	merge(v, beg, mid, end);
}

#ifdef OPTIMIZE__

//���ֺϲ����㷨����������Ҫ��ʡһ��Ŀռ䣬����д���ϲ�������
void merge(std::vector<int> &v, size_t beg, size_t mid, size_t end)
{
	auto iterM = v.begin() + beg;
	//����ǰ������:[beg, mid)
	std::vector<int> a(v.begin() + beg, v.begin() + mid);
	auto iterA = a.begin();
	auto iterB = v.begin() + mid;
	while (iterA != a.end() || iterB != v.begin() + end)
	{
		if (iterA != a.end() && (iterB == v.begin() + end || *iterA <= *iterB)) *iterM++ = *iterA++;
		if (iterB != v.begin() + end && (iterA == a.end() || *iterB <= *iterA)) *iterM++ = *iterB++;
	}
}

#else

void merge(std::vector<int> &v, size_t beg, size_t mid, size_t end)
{
	auto iterM = v.begin() + beg;
	//����ǰ������:[beg, mid)
	std::vector<int> a(v.begin() + beg, v.begin() + mid);
	//���ƺ�������:[mid, end)
	std::vector<int> b(v.begin() + mid, v.begin() + end);
	auto iterA = a.begin();
	auto iterB = b.begin();
	while (iterA != a.end() || iterB != b.end())
	{
		if (iterA != a.end() && (iterB == b.end() || *iterA <= *iterB)) *iterM++ = *iterA++;
		if (iterB != b.end() && (iterA == a.end() || *iterB <= *iterA)) *iterM++ = *iterB++;
	}
}

#endif