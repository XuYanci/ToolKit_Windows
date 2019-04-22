#include "Application\PreCompile.h"
#include "Tool\Encoding\ASCII.h"
#include "Tool\Encoding\Unicode.h"
#include "String.h"

using namespace System::BasicType;

///************************************************************************
/// <summary>
/// Contruct an empty string
/// </summary>
/// <returns></returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::String() :m_Length(0), m_Disposed(false)
{
	this->Initialize(_T(""));
}


///************************************************************************
/// <summary>
/// Contruct an string with STL String
/// </summary>
/// <param name=StdString OtherStdString>std String</param>
/// <returns></returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::String(StdString& OtherStdString) :m_Length(0), m_Disposed(false)
{
	this->Initialize(OtherStdString);
}


///************************************************************************
/// <summary>
/// Contruct an string with C-type String
/// </summary>
/// <param name=pStr>C-type String</param>
/// <returns></returns>
/// <remarks>
///  none
/// </remarks>
///***********************************************************************
String::String(CharArray pString) :m_Length(0), m_Disposed(false)
{
	this->Initialize(pString);
}


///************************************************************************
/// <summary>
/// Destruct the string
/// </summary>
/// <returns></returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::~String()
{
	this->Destroy();
}


///************************************************************************
/// <summary>
/// Allow the string copying
/// </summary>
/// <param name=other>another String string</param>
/// <returns></returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::String(const String& other)
{
	this->SetStdString(other.GetStdString());
	this->SetLength(other.GetLength());
	this->m_WideArray = other.m_WideArray;
	this->SetDisposed(other.GetDisposed());
}


///************************************************************************
/// <summary>
/// Allow the obejct assignment
/// </summary>
/// <param name=other>another String string</param>
/// <returns>the refernce of current String</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->SetStdString(other.GetStdString());
		this->SetLength(other.GetLength());
		this->m_WideArray = other.m_WideArray;
		this->SetDisposed(other.GetDisposed());
	}

	return *this;
}


///************************************************************************
/// <summary>
/// Init the String
/// </summary>
/// <param name=StdString OtherStdString>Std String</param>
/// <returns></returns>
/// <remarks>
/// Note: it can transfer C-type String to be Std String
/// </remarks>
///***********************************************************************
String::Empty String::Initialize(StdString OtherStdString)
{
	// Set the default std String
	this->SetStdString(OtherStdString);

	// Set length of the String
	this->SetLength((Length)this->GetStdString().length());
}


///************************************************************************
/// <summary>
/// Destory the String
/// </summary>
/// <returns></returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::Empty String::Destroy()
{
	if (!this->GetDisposed())
	{
		this->SetDisposed(true);

	}
}


///************************************************************************
/// <summary>
/// Append a new std String to the String
/// </summary>
/// <param name=str>std String</param>
/// <returns>the current String</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String& String::Append(StdString& OtherStdString)
{
	// Set the std String
	this->SetStdString(this->GetStdString().append(OtherStdString));

	// Set the length
	this->SetLength((Length)this->GetStdString().length());

	return *this;
}


///************************************************************************
/// <summary>
/// Is the current String equals to the other one
/// </summary>
/// <param name=other>the other String</param>
/// <returns>false��not eqaul true��equal</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::BOOL String::Equal(String& OtherString)
{
	BOOL bEqual = false;

	if (this->GetStdString().compare(OtherString.GetStdString()) == 0)
	{
		bEqual = true;
	}

	return bEqual;
}


///************************************************************************
/// <summary>
/// Cohesion String to be a new String
/// </summary>
/// <param name=str>String</param>
/// <returns>current String</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String& String::operator+(String& OtherString)
{
	return Append(OtherString.GetStdString());
}


///************************************************************************
/// <summary>
/// Cohesion std String to be a new String
/// </summary>
/// <param name=str>std String</param>
/// <returns>current String</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String& String::operator+(StdString& OtherStdString)
{
	return Append(OtherStdString);
}


///************************************************************************
/// <summary>
/// Cohesion C-type String to be a new String
/// </summary>
/// <param name=str>C String value</param>
/// <returns>currrent String</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String& String::operator+(CharArray pString)
{
	return Append(StdString(pString));
}


///************************************************************************
/// <summary>
/// Is String equals to the other one
/// </summary>
/// <param name=other>another String</param>
/// <returns>false��not equal true��equal</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::BOOL String::operator==(String& other)
{
	BOOL bEqual = false;

	if (this->GetStdString().compare(other.GetStdString()) == 0)
	{
		bEqual = true;
	}

	return bEqual;
}


///************************************************************************
/// <summary>
/// Is std String equals to the String
/// </summary>
/// <param name=StdString & OtherStdString>Std String</param>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String::BOOL String::operator==(StdString& OtherStdString)
{
	BOOL bEqual = false;

	if (this->GetStdString().compare(OtherStdString) == 0)
	{
		bEqual = true;
	}

	return bEqual;
}


///************************************************************************
/// <summary>
/// Is String not equals to the other one
/// </summary>
/// <param name=other>another String</param>
/// <returns>false��equal true��not equal</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::BOOL String::operator!=(String& OtherString)
{
	BOOL bEqual = false;

	if (this->GetStdString().compare(OtherString.GetStdString()) != 0)
	{
		bEqual = true;
	}

	return bEqual;
}


///************************************************************************
/// <summary>
/// Is std String not equals to the String
/// </summary>
/// <param name=StdString & OtherStdString></param>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String::BOOL String::operator!=(StdString& OtherStdString)
{
	BOOL bEqual = false;

	if (this->GetStdString().compare(OtherStdString) != 0)
	{
		bEqual = true;
	}

	return bEqual;
}


///************************************************************************
/// <summary>
/// Get C-type string
/// </summary>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String::operator LPCTSTR() const
{
	return this->GetStdString().c_str();
}


///************************************************************************
/// <summary>
/// Split the String by a seperator
/// </summary>
/// <param name=ch>seperator</param>
/// <returns>a String arrray</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String::BOOL String::Split(String strSeperator, StringTable& vStringTable)
{
	BOOL bSuccess = false;

	// Set the current character's position
	Index iCurrentIndex = this->Find(strSeperator, 0);
	
	// Loop to vector
	Index iStartIndex = 0;
	while (StdString::npos != iCurrentIndex)
	{
		// Get the splited string
		String strSplitedString = this->SubString(iStartIndex, iCurrentIndex - iStartIndex);

		// Push the subString to the vector
		vStringTable.push_back(strSplitedString);

		// Update the start position of original String
		iStartIndex = iCurrentIndex + (Index)strSeperator.GetStdString().size();

		// Set the current character's position
		iCurrentIndex = this->Find(strSeperator, iStartIndex);
	}

	// There is no searching result
	if (iStartIndex == 0)
	{
		return bSuccess;
	}

	// The searching is to be end
	if (iStartIndex != this->GetLength())
	{
		// Get the last splited string
		String strSplitedString = this->SubString(iStartIndex, (Length)StdString::npos);

		// Push the subString to the vector
		vStringTable.push_back(strSplitedString);
	}

	bSuccess = true;

	return bSuccess;
}


///************************************************************************
/// <summary>
/// Sub the String to get a new String
/// </summary>
/// <param name=startIndex>start position</param>
/// <param name=length>distance of subbing</param>
/// <returns>A new String</returns>
/// <remarks>
/// none
/// </remarks>
///***********************************************************************
String String::SubString(Index iStartIndex, Length iSubLength)
{
	if (iStartIndex<0 || iSubLength>this->GetLength())
	{
		return _T("");
	}

	return this->GetStdString().substr(iStartIndex, iSubLength);
}


///************************************************************************
/// <summary>
/// Find the last appearance character in the string and return its's position
/// </summary>
/// <param name=String SpecialStr></param>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String::Index String::FindLast(String strSpecialStr)
{
	return (Index)(this->GetStdString().find_last_of(strSpecialStr));
}


///************************************************************************
/// <summary>
/// Find the appearance character in the string and return its's position
/// </summary>
/// <param name=Index iStartPos>Start finding position</param>
/// <param name=String SpecialStr>The string that you want to find</param>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String::Index String::Find(String strSpecialStr, Index iStartPos)
{
	Index iFindPos = (Index)(StdString::npos);

	if (iStartPos < 0 || strSpecialStr == _T(""))
	{
		return iFindPos;
	}

	iFindPos = (Index)(this->GetStdString().find(strSpecialStr, iStartPos));

	return iFindPos;
}


///************************************************************************
/// <summary>
/// Replace the string by another one
/// </summary>
/// <param name=Index iReplacePos></param>
/// <param name=Length iReplaceLength></param>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String& String::Replace(Index iReplacePos, Length iReplaceLength, String strReplaceString)
{
	if (iReplacePos < 0 || iReplaceLength<0 || iReplaceLength>this->GetLength() || strReplaceString == _T(""))
	{
		return *this;
	}

	this->GetStdString().replace(iReplacePos, iReplaceLength, strReplaceString);

	return *this;
}


///************************************************************************
/// <summary>
/// Get the wide string when you are in ASCII environment to program
/// </summary>
/// <returns></returns>
/// <remarks>
/// Note: you are in ASCII mode so that you need this function or it is no need.
/// </remarks>
///***********************************************************************
System::WByteArray String::AllocWideString()
{
	// Get the ASCII string at first
	std::string strAsciiString = System::Encoding::ASCII::GetString(this->GetStdString());

	// Create an ascii array 
	Array<SByte> AsciiArray((Int32)strAsciiString.length() + 1);

	// Copy the Ascii string to the Ascii buffer
	Array<SByte>::Copy((SByteArray)strAsciiString.c_str(), (Int32)strAsciiString.length(), AsciiArray, AsciiArray.Size());

	// Get the wide string from the ascii array
	std::wstring strWideString = System::Encoding::Unicode::GetString(AsciiArray, 0, AsciiArray.Size(), EncodeType::E_ASCII);

	// Resize the wide array
	this->m_WideArray.Resize((Length)strWideString.length());

	// Fill the wide array
	Array<WByte>::Copy((WByteArray)strWideString.data(), (Length)strWideString.length(), this->m_WideArray, this->m_WideArray.Size());

	return this->m_WideArray;
}


///************************************************************************
/// <summary>
/// Make string upper
/// </summary>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String& String::MakeUpper()
{
#ifdef UNICODE
	transform(this->GetStdString().begin(), this->GetStdString().end(), this->GetStdString().begin(), towupper);

#else
	transform(this->GetStdString().begin(), this->GetStdString().end(), this->GetStdString().begin(), toupper);

#endif
	
	return *this;
}


///************************************************************************
/// <summary>
/// Make string lower
/// </summary>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String& String::MakeLower()
{
#ifdef UNICODE
	transform(this->GetStdString().begin(), this->GetStdString().end(), this->GetStdString().begin(), towlower);

#else
	transform(this->GetStdString().begin(), this->GetStdString().end(), this->GetStdString().begin(), tolower);

#endif

	return *this;
}


///************************************************************************
/// <summary>
/// Get a character from the string at special position
/// </summary>
/// <param name=Index iPos></param>
/// <returns></returns>
/// <remarks>
/// None
/// </remarks>
///***********************************************************************
String::Character String::operator[](Index iPos)
{
	if (iPos < 0 || iPos >= this->GetLength())
	{
		return _T('N');
	}

	return this->GetStdString()[iPos];
}