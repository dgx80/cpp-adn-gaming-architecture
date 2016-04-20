#include "base.h"

namespace DX
{
int base::s_nCounter = 0;

base::base(void)
: m_nId( s_nCounter++ )
{
}

base::~base(void)
{
}
}