/*
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
# The Original Code is Copyright (C) 2009 by exherb (htpp://4leaf.me).
# All rights reserved.
#
# The Original Code is: all of this file.
#
# Contributor(s): none yet.
#
*/
#include "stdafx.h"
#include "ole_drop_source.h"


CHOleDataSource::CHOleDataSource( void ): m_currentIndex(0)
{

}

CHOleDataSource::~CHOleDataSource( void )
{

}

BOOL CHOleDataSource::OnRenderFileData( LPFORMATETC lpFormatEtc, CFile* pFile )
{
	if(lpFormatEtc->cfFormat == RegisterClipboardFormat(CFSTR_FILECONTENTS))
	{   
		m_indexList->CopyItemToCFile(m_items[lpFormatEtc->lindex], pFile);
		return TRUE;
	}
	return COleDataSource::OnRenderFileData(lpFormatEtc, pFile);
}

void CHOleDataSource::SetAssociat( const std::vector<int> &items, CIOSDirectoryTree *iOsDirectoryTree )
{
	m_items = items;
	m_indexList = iOsDirectoryTree;
}
