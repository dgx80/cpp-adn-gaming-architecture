#ifndef _DX_Data_h
#define _DX_Data_h

#include "DXDefine.h"
#include <vector>

// namespace
namespace DX
{
namespace Data
{
class xValue
{
public:

	xValue()
		: m_bInteger(true)
		, m_sValue("")
		, m_nValue(0)
	{}
	xValue(const dxString &val)
		: m_bInteger(false)
		, m_sValue(val)
		, m_nValue(0)
	{}
	xValue(const int &val)
		: m_bInteger(true)
		, m_sValue("")
		, m_nValue(val)
	{}
		
	virtual ~xValue()
	{}
		
	const int& GetValue() const { return m_nValue; }

	void SetValue( const dxString & val ){ m_sValue = val; m_bInteger = false;}
	void SetValue( const int & val ) { m_nValue = val; m_bInteger = true;}

	bool IsInteger() const { return m_bInteger; }

private:
	dxString	m_sValue;
	int			m_nValue;
	bool		m_bInteger;

};

typedef std::vector<xValue> xValueVec; 

class xLine
{
public:
	xLine(int nValueCount = 1)
		: Name("")
		, m_nReservedMemory( nValueCount )
	{
		Init();
	}
	xLine( const dxString &name, int nValueCount = 1)
		: Name(name)
		, m_nReservedMemory( nValueCount )
	{
		Init();
	}

	virtual ~xLine()
	{
		m_vValues.clear();
	}

	void PushBackValue(const int & val)
	{
		xValue o(val);
		m_vValues.push_back(o);
	}
	void PushBackValue(const dxString & val)
	{
		xValue o(val);
		m_vValues.push_back(o);
	}

	int GetSize() const
	{
		return static_cast<int>(m_vValues.size());
	}
	void AppendValue(const int & val, const int &nCol)
	{
		AjustVectorSize(nCol);
		m_vValues.push_back(xValue(val));
		
	}
	void AppendValue(const dxString & val, const int &nCol)
	{
		AjustVectorSize(nCol);
		m_vValues.push_back(xValue(val));
	}

	xLine & operator=(const xLine& l)
	{
		m_vValues.clear();
		
		m_nReservedMemory = l.GetReservedMemory();
		

		
		int nCol =  l.GetSize();

		for(int i = 0;i < nCol; i++)
		{
		//	m_vValues.push_back
		}


		return *this;
	}
	dxString Name; 
	
protected:

	const int& GetReservedMemory() const { return m_nReservedMemory; }

private:
	void Init()
	{
		m_vValues.reserve(m_nReservedMemory);
	}
	void AjustVectorSize(const int & nCol)
	{
		if( nCol >= m_nReservedMemory )
		{
			m_vValues.reserve(nCol+1);
			m_nReservedMemory = nCol+1;
		}
		for(int i = static_cast<int>(m_vValues.size()); i < nCol; i++)
		{
			m_vValues.push_back(xValue());
		}
	}

	xValueVec m_vValues;
	int m_nReservedMemory;
};
class DataTable
{
public:
	// Constructors
	DataTable(const int &nCol, const int &nLine)
	{
		m_vLine.reserve(nLine);

		for(int i = 0;i < nLine; i++)
		{
			m_vLine.push_back(xLine("",nCol));
		}
	}
	// Destructor
	virtual ~DataTable()
	{
		m_vLine.clear();
	}

	int GetCollumnsCount() const
	{
		if(m_vLine.empty() )
			return 0;

		return Lines(0).GetSize();
	}
	int GetLinesCount() const
	{
		if(m_vLine.empty() )
			return 0;

		return static_cast<int>(m_vLine.size());
	}
	void SetLineName(const int& nIndex, const dxString & sName)
	{
		if(!AssertLine(nIndex))
			return;

		m_vLine[nIndex].Name = sName;
	}

	xLine & Lines(int nIndex)
	{
		return m_vLine[nIndex];
	}
	const xLine & Lines(int nIndex) const
	{
		return m_vLine[nIndex];
	}
	const DataTable & operator =( const DataTable & /*other*/)
	{
		m_vLine.clear();
		
//		int nLine = other.GetLinesCount();

//		for(int i = 0;i < nLine; i++)
		{
//			m_vLine.push_back(xLine(2));
		}

		return *this;
	}
	dxString Name;
	typedef std::vector<xLine> LineVector;


private:

	bool AssertLine(const int & nIndex)
	{
		if( nIndex >= static_cast<int>(m_vLine.size()) 
			|| nIndex < 0)
			return false;
		return true;
	}

	LineVector m_vLine;

};
class DataSet
{
public:
	// Constructors
	DataSet(){}
	// Destructor
	virtual ~DataSet(){}

private:
};


}// Data namespace end
}// DX namespace end

#endif
