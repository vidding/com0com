/*
 * $Id$
 *
 * Copyright (c) 2004-2005 Vyacheslav Frolov
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *
 * $Log$
 * Revision 1.1  2005/01/26 12:18:54  vfrolov
 * Initial revision
 *
 *
 */

#ifndef _TRACE_H_
#define _TRACE_H_

#if DBG

#define TRACE_FLAG_PARAMS         0x0001
#define TRACE_FLAG_RESULTS        0x0002

typedef struct _CODE2NAME {
  ULONG code;
  PWCHAR name;
} CODE2NAME, *PCODE2NAME;

VOID TraceOpen(
    IN PDRIVER_OBJECT _pDrvObj,
    IN PUNICODE_STRING pRegistryPath);

VOID TraceClose();

VOID Trace0(
    IN PC0C_COMMON_EXTENSION pDevExt,
    IN PWCHAR pStr);

VOID Trace00(
    IN PC0C_COMMON_EXTENSION pDevExt,
    IN PWCHAR pStr1,
    IN PWCHAR pStr2);

VOID TraceCode(
    IN PC0C_COMMON_EXTENSION pDevExt,
    IN PCHAR pHead,
    IN PCODE2NAME pTable,
    IN ULONG code,
    IN PNTSTATUS pStatus);

VOID TraceMask(
    IN PC0C_COMMON_EXTENSION pDevExt,
    IN PCHAR pHead,
    IN PCODE2NAME pTable,
    IN ULONG mask);

VOID TraceIrp(
    IN PCHAR pHead,
    IN PIRP pIrp,
    IN PNTSTATUS pStatus,
    IN ULONG flags);

CODE2NAME codeNameTableWaitMask[];
CODE2NAME codeNameTablePurgeMask[];
CODE2NAME codeNameTableIoctl[];
CODE2NAME codeNameTablePnp[];
CODE2NAME codeNameTablePower[];
CODE2NAME codeNameTableDoType[];
CODE2NAME codeNameTableModemStatus[];
CODE2NAME codeNameTableControlHandShake[];
CODE2NAME codeNameTableFlowReplace[];
CODE2NAME codeNameTableStatus[];
CODE2NAME codeNameTableIrpMj[];
CODE2NAME codeNameTableRelations[];
CODE2NAME codeNameTableBusQuery[];
CODE2NAME codeNameTableDeviceText[];

#else /* DBG */

#define TraceOpen(a1, a2)
#define TraceClose()
#define Trace0(a1, a2)
#define Trace00(a1, a2, a3)
#define TraceCode(a1, a2, a3, a4, a5)
#define TraceMask(a1, a2, a3, a4)
#define TraceIrp(a1, a2, a3, a4)

#endif /* DBG */

#endif /* _TRACE_H_ */