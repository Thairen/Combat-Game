#include "Stat.h"



Stat::Stat(float max) : m_current(max), m_max(max)
{
}

void Stat::BalanceStat()
{
	if (m_current > m_max)
		m_current = m_max;
}
