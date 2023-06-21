#include <HyperXCmd.h>

typedef unsigned long ui5b;
typedef unsigned short ui4b;
typedef unsigned char ui3b;

typedef long si5b;
typedef short si4b;
typedef char si3b;

#define blnr int
#define trueblnr 1
#define falseblnr 0

#define UseParamBuffersExtension 1
#define UseHostClipExchangeExtension 1

#include "ExtnGlue.i"

pascal void main(XCmdPtr paramPtr) {
	XtnsDR xdr;

	if (noErr == InitExtensions(&xdr)) {
		ui4b Pbuf_No;
		if (paramPtr->paramCount == 0) {
			if (noErr == HTCImport(&xdr, &Pbuf_No)) {
				ui5b len;
				if (noErr == PBufGetSize(&xdr, Pbuf_No, &len)) {
					Handle h = NewHandle(len);
					if (h != NULL) {
						if (noErr == PbufTransfer(&xdr, *h, Pbuf_No, 0, len, falseblnr)) {
							paramPtr->returnValue = NewHandle(len + 1);
							BlockMove(*h, (*paramPtr->returnValue), len);
							((char*)*paramPtr->returnValue)[len] = 0;
						}
						DisposHandle(h);
					}
				}
				(void) PbufDispose(&xdr, Pbuf_No);
			}
		} else {
			ui5b len = GetHandleSize(paramPtr->params[0]) - 1;
			if (noErr == PbufNew(&xdr, len, &Pbuf_No)) {
				if (noErr != PbufTransfer(&xdr, *paramPtr->params[0], Pbuf_No, 0, len, trueblnr)) {
					(void) PbufDispose(&xdr, Pbuf_No);
				} else {
					(void) HTCExport(&xdr, Pbuf_No);
				}
			}
		}
	}
}