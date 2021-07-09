#include "Header.h"

int main()
{
	DANHSACHTHUCUNG danhSach;
	chayMenu(danhSach, chonLenh(menu()));
	//KhoiTaoDanhSachRong(danhSach);
	//NhapDanhSachThuCung(danhSach);
	//XoaTheCoTrongLuongLonHonNguong(danhSach);
	// giải phóng bộ nhớ sau khi chương trình được tắt
	XoaDanhSach(danhSach);
	return 0;
}
