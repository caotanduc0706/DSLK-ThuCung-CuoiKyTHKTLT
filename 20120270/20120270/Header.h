#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

// cấu trúc mang thông tin của một con thú cưng
struct ThongTinThuCung
{
	string _MaSo = "";
	string _Ten = "";
	double _KhoiLuong = 0;
	int _Tuoi = 0;
	string _MauSac = "";
};

// cấu trúc của một thẻ lưu thông tin thú cưng trong Danh Sách
typedef struct TheThuCung* conTroThe;
struct TheThuCung
{
	ThongTinThuCung thongTin;
	conTroThe theTiepTheo = NULL;
};

// cấu trúc một danh sách liên kết đơn lưu thông tin danh sách thú cưng
struct DANHSACHTHUCUNG
{
	int _SoLuong = -1; //giá trị mặc định bằng -1 ứng với việc chưa khởi tạo danh sách
	conTroThe theDau = NULL; // con trỏ tới thẻ đầu tiên
	conTroThe theCuoi = NULL; // con trỏ tới thẻ cuối cùng
};

// khởi tạo danh sách rỗng
void KhoiTaoDanhSachRong(DANHSACHTHUCUNG& danhSach);
// hàm kiểm tra xem một danh sách thú cưng có rỗng hay không
bool KiemTraRong(DANHSACHTHUCUNG danhSach);
// kiểm tra một xâu có chứa khoảng trắng hay không
bool coChuaKhoangTrang(string xauCanKiemTra);
// Hàm nhập thông tin của một thẻ (thú cưng)
void NhapThongTinMotThuCung(DANHSACHTHUCUNG danhSach, ThongTinThuCung& thuCung);
// hàm nhập một danh sách thú cưng
void NhapDanhSachThuCung(DANHSACHTHUCUNG& danhSach);
// thêm một thẻ vào cuối danh sách
void ThemTheVaoCuoiDanhSach(DANHSACHTHUCUNG& danhSach, conTroThe theCanChen);
// xóa rỗng một danh sách
void XoaDanhSach(DANHSACHTHUCUNG& danhSach);
// hàm xuất một thông tin thú cưng
void XuatThongTinMotThe(ThongTinThuCung thuCung);
// hàm xuất thông tin thú cưng có trong danh sách
void XuatDanhSachThuCung(DANHSACHTHUCUNG danhSach);
// hàm tìm địa chỉ tới thẻ có mã số
conTroThe TimTheCoMaSo(DANHSACHTHUCUNG danhSach, string MaSo);
// hàm bán thú cưng
void BanThuCung(DANHSACHTHUCUNG& danhSach);
// xóa thẻ có địa chỉ
void XoaTheCoDiaChi(DANHSACHTHUCUNG& danhSach, conTroThe theCanXoa);
// hàm này giúp thay dổi màu long củ thú cưng nếu mà số người dùng nhập là một số hợp lệ
void CapNhatMauLong(DANHSACHTHUCUNG& danhSach);
// hàm thê một thú cưng tại môt vị trí cho trước
void ThemMotThe(DANHSACHTHUCUNG& danhSach);
// hàm xóa đồng loạt các thú cưng có trọng lượng lớn hơn ngưỡng K
void XoaTheCoTrongLuongLonHonNguong(DANHSACHTHUCUNG& danhSach);

// các hàm khởi tạo giao diện và tương tác với menu
// hiển thị nội dung menu
int menu();
// chọn lênh của menu
int chonLenh(int soLenh);
// chạy menu
void chayMenu(DANHSACHTHUCUNG& danhSach, int lenh);