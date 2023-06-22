# minivmac-hostclipboardxfcn

HyperCard XFCN for use with the Mini vMac emulator that lets you read and/or write the host computer's clipboard from inside the emulator.

**Note:** While this code was developed and compiled on Mini vMac under System 6.0.8, the files were packaged up for GitHub on MacOS 9, so the version of StuffIt used for compressing the `.sit` files may be too new for unpacking them in vMac directly.

## Syntax

Once you have built the XFCN using the included Think C 6 project as a code resource, you use it from inside HyperCard in one of two forms:

    put hostClipboard() into copiedText

Retrieves whatever is on the host clipboard right now and stores it in the variable `copiedText`.

    get hostClipboard("New text you want to copy.")

Copies the given string (in this example `New text you want to copy.`) to the host's clipboard, so you can paste it outside the emulator.

## License

XFCN written by Uli Kusterer, based on the ClipIn/ClipOut DAs by Paul C. Pratt.

	You can redistribute these files and/or modify them under the terms
	of version 2 of the GNU General Public License as published by
	the Free Software Foundation.  You should have received a copy
	of the license along with these files; see the file COPYING.

	This file is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	license for more details.
