#pragma once
#ifndef _DX_GridOffset_h
#define _DX_GridOffset_h

#include "base.h"
#include <pf/pflib.h>

namespace DX
{
namespace Math
{
class GridOffset
{
public:
    GridOffset( int a_nXInit, int a_nXSpace, int a_nYInit, int a_nYSpace )
        : nXInit(a_nXInit)
        , nXSpace(a_nXSpace)
        , nYInit(a_nYInit)
        , nYSpace(a_nYSpace)
    {
    }
    GridOffset()
        : nXInit(0)
        , nXSpace(0)
        , nYInit(0)
        , nYSpace(0)
    {
    }

    void GetPosition( int a_nLine, int a_nCollumn, TVec2 & a_orPosition )
    {
        a_orPosition.x = static_cast<TReal>( nXInit + a_nCollumn * nXSpace );
        a_orPosition.y = static_cast<TReal>( nYInit + a_nLine * nYSpace );
    }

    void GetOffset( int a_nLine, int a_nCollumn, TVec2 & a_orOffset )
    {
        a_orOffset.x = static_cast<TReal>( a_nCollumn * nXSpace );
        a_orOffset.y = static_cast<TReal>( a_nLine * nYSpace );
    }

    void Assign( const GridOffset & a_oGrid )
    {
        nXInit = a_oGrid.nXInit;
        nYInit = a_oGrid.nYInit;
        nXSpace = a_oGrid.nXSpace;
        nYSpace = a_oGrid.nYSpace;
    }

    int nXInit;
    int nYInit;
    int nXSpace;
    int nYSpace;
};

}//Math
}//DX
#endif