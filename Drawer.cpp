#include "Drawer.h"

#include "Vect2.h"
#include "Convertion.h"

namespace DX
{
namespace Graphic
{
void Drawer::DrawLine( const DX::Point & ptO,const DX::Point & ptD, const DX::Graphic::Color & rColor  )
{
	TVec2 from, to;

	Toolbox::Convertion::ObtainTVec2FromPoint(ptO,from);
	Toolbox::Convertion::ObtainTVec2FromPoint(ptD, to);

	TRenderer * r = TRenderer::GetInstance();

	TTransformedLitVert verts[2];

	TVec2 perp = to-from;
	std::swap( perp.x, perp.y );
	perp.Normalize();
	perp *= 2;

	verts[0].pos = TVec3(from,1);
	verts[1].pos = TVec3(to,1);

	verts[0].uv=TVec2(0,0);
	verts[1].uv=TVec2(2,0);

	TColor oCol = rColor.GetPFColor();

	verts[0].color = TColor32( oCol);
	
	verts[1].color = verts[0].color;

	r->DrawVertices( TRenderer::kDrawLines, TVertexSet( verts,2 ) );
}
void Drawer::DrawLine( const DX::Graphic::Vect2 & oVec, const DX::Graphic::Color & rColor )
{
	DrawLine(oVec, oVec.GetDestination(),rColor);
}
void Drawer::DrawPixel( const DX::Point & a_rPoint, const DX::Graphic::Color & rColor )
{
	TVec2 from;

	Toolbox::Convertion::ObtainTVec2FromPoint(a_rPoint,from);

	TRenderer * r = TRenderer::GetInstance();

	TTransformedLitVert verts[2];

	TVec2 perp(0,0);
	std::swap( perp.x, perp.y );
	perp.Normalize();
	perp *= 2;

	verts[0].pos = TVec3(from,1);
	verts[1].pos = TVec3(from,1);

	verts[0].uv=TVec2(0,0);
	verts[1].uv=TVec2(1,0);

	TColor oCol = rColor.GetPFColor();

	verts[0].color = TColor32( oCol );
	verts[1].color = verts[0].color;

	r->DrawVertices( TRenderer::kDrawPoints, TVertexSet( verts,2 ) );
}
}//Graphic
}//DX