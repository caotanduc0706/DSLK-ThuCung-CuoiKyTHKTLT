#include "Header.h"

// hàm khởi tạo danh sách rỗng
void KhoiTaoDanhSachRong(DANHSACHTHUCUNG& danhSach)
{
	danhSach._SoLuong = 0;
	danhSach.theDau = NULL;
	danhSach.theCuoi = NULL;
}

// kiểm tra một xâu có chứa khoảng trắng hay không
bool coChuaKhoangTrang(string xauCanKiemTra)
{
	int chieuDaiXau = xauCanKiemTra.size();
	for (int i = 0; i < chieuDaiXau; i++)
		if (xauCanKiemTra[i] == ' ')
			return true;
	return false;
}

// nhập thông tin của một thú cưng
void NhapThongTinMotThuCung(DANHSACHTHUCUNG danhSach, ThongTinThuCung& thuCung)
{
	// biến dùng để nhập tạm và xử lý thong tin đầu vào
	string bienNhapTam = "";
	cin.ignore();
	cout << setiosflags(ios::left) << setw(60) << "Nhap ma so cua thu cung (bang 7 ky tu) ";
	cout << ":";
	getline(cin, bienNhapTam);
	// nếu số phần tử của mã số không phải bằng bày hay nó chứa khoảng trắng thì cho người dùng tiếp tục nhập cho đến khi nào nhập đúng
	while (bienNhapTam.size() != 7 || coChuaKhoangTrang(bienNhapTam) == true || TimTheCoMaSo(danhSach, bienNhapTam) != NULL)
	{
		cout << "Vui long kiem tra MA SO thu cung ban vua nhap." << endl;
		cout << setiosflags(ios::left) << setw(60) << "Nhap lai MA SO thu cung ";
		cout << ":";
		getline(cin, bienNhapTam);
	}
	// sau khi nhập thành công gán vào mã số
	thuCung._MaSo = bienNhapTam;
	
	cout << endl;
	cout << setiosflags(ios::left) << setw(60) << "Nhap ten cua thu cung (toi da 30 phan tu) ";
	cout << ":";
	getline(cin, bienNhapTam);
	while (bienNhapTam.size() > 30)
	{
		cout << setiosflags(ios::left) << setw(60) << "TEN khong hop le, nhap lai ";
		cout << ":";
		getline(cin, bienNhapTam);
	}
	// sau khi nhập tên đúng và thành công, gán vào phần tên
	thuCung._Ten = bienNhapTam;

	// nhập màu sắc của thú cưng
	cout << endl;
	cout << setiosflags(ios::left) << setw(60) << "Nhap mau sac cua thu cung (vang, nau, trang, den, xam) ";
	cout << ":";
	getline(cin, bienNhapTam);
	// nếu không phải các màu vàng, nâu, trang, den hoặc xám thì nhập lại
	while (!(bienNhapTam == "vang" || bienNhapTam == "nau" || bienNhapTam == "trang" || bienNhapTam == "den" || bienNhapTam == "xam"))
	{
		cout << setiosflags(ios::left) << setw(60) << "Khong co MAU SAC ban vua nhap, nhap lai ";
		cout << ":";
		getline(cin, bienNhapTam);
	}
	thuCung._MauSac = bienNhapTam;

	// nhập khối lượng thú cưng
	cout << endl;
	bool kiemTraNhapSai = false; // kiểm tra xem có nhập đúng kiểu dữ liệu hay không
	cout << setiosflags(ios::left) << setw(60) << "Nhap khoi luong cua thu cung ";
	cout << ":";
	do
	{
		cin >> thuCung._KhoiLuong;
		kiemTraNhapSai = cin.fail();
		if (kiemTraNhapSai == true || thuCung._KhoiLuong <= 0)
		{
			// xóa phần thông tin nhập sai
			cin.clear();
			cin.ignore(1000, '\n');
			// thông báo nhập lại
			cout << setiosflags(ios::left) << setw(60) << "KHOI LUONG khong hop le, nhap lai ";
			cout << ":";
		}
	} while (kiemTraNhapSai == true || thuCung._KhoiLuong <= 0);

	// nhập tuổi thú cưng
	cout << endl;
	kiemTraNhapSai = false; // kiểm tra xem có nhập đúng kiểu dữ liệu hay không
	cout << setiosflags(ios::left) << setw(60) << "Nhap tuoi cua thu cung ";
	cout << ":";
	do
	{
		cin >> thuCung._Tuoi;
		kiemTraNhapSai = cin.fail();
		if (kiemTraNhapSai == true || thuCung._Tuoi <= 0)
		{
			// xóa phần thông tin nhập sai
			cin.clear();
			cin.ignore(1000, '\n');
			// thông báo nhập lại
			cout << setiosflags(ios::left) << setw(60) << "TUOI hop le, nhap lai ";
			cout << ":";
		}
	} while (kiemTraNhapSai == true || thuCung._Tuoi <= 0);
}

// hàm xuất một thông tin thú cưng
void XuatThongTinMotThe(ThongTinThuCung thuCung)
{
	// in dòng gạch ngang
	for (int i = 0; i < 101; i++)
		cout << "-";
	cout << endl;
	cout << "|" << setiosflags(ios::left) << setw(15) << "Ma so";
	cout << "|" << setiosflags(ios::left) << setw(45) << "Ten";
	cout << "|" << setiosflags(ios::left) << setw(15) << "Mau sac";
	cout << "|" << setiosflags(ios::left) << setw(15) << "KL (Kg)";
	cout << "|" << setiosflags(ios::left) << setw(5) << "Tuoi";
	cout << "|" << endl;
	// in dòng gạch ngang
	for (int i = 0; i < 101; i++)
		cout << "-";
	cout << endl;
	cout << "|" << setiosflags(ios::left) << setw(15) << thuCung._MaSo;
	cout << "|" << setiosflags(ios::left) << setw(45) << thuCung._Ten;
	cout << "|" << setiosflags(ios::left) << setw(15) << thuCung._MauSac;
	cout << "|" << setiosflags(ios::left) << setw(15) << thuCung._KhoiLuong;
	cout << "|" << setiosflags(ios::left) << setw(5) << thuCung._Tuoi;
	cout << "|" << endl;
	for (int i = 0; i < 101; i++)
		cout << "-";
	cout << endl;
}

// hàm xuất thông tin thú cưng có trong danh sách
void XuatDanhSachThuCung(DANHSACHTHUCUNG danhSach)
{
	if (KiemTraRong(danhSach) == true)
		cout << "Danh sach thu cung rong." << endl;
	else
	{
		cout << endl << "Danh sach thu cung cua ban la." << endl;
		int i = 0;
		cout << endl << endl;
		// in dòng gạch ngang
		for (int i = 0; i < 107; i++)
			cout << "-";
		cout << endl;
		cout << "|" << setiosflags(ios::left) << setw(5) << "STT";
		cout << "|" << setiosflags(ios::left) << setw(15) << "Ma so";
		cout << "|" << setiosflags(ios::left) << setw(45) << "Ten";
		cout << "|" << setiosflags(ios::left) << setw(15) << "Mau sac";
		cout << "|" << setiosflags(ios::left) << setw(15) << "KL (Kg)";
		cout << "|" << setiosflags(ios::left) << setw(5) << "Tuoi";
		cout << "|" << endl;
		// in dòng gạch ngang
		for (int i = 0; i < 107; i++)
			cout << "-";
		cout << endl;
		// xuất từng thẻ
		for (conTroThe p = danhSach.theDau; p; p = p->theTiepTheo)
		{
			
			cout << "|" << setiosflags(ios::left) << setw(5) << i++;
			cout << "|" << setiosflags(ios::left) << setw(15) << p->thongTin._MaSo;
			cout << "|" << setiosflags(ios::left) << setw(45) << p->thongTin._Ten;
			cout << "|" << setiosflags(ios::left) << setw(15) << p->thongTin._MauSac;
			cout << "|" << setiosflags(ios::left) << setw(15) << p->thongTin._KhoiLuong;
			cout << "|" << setiosflags(ios::left) << setw(5) << p->thongTin._Tuoi;
			cout << "|" << endl;
			for (int i = 0; i < 107; i++)
				cout << "-";
			cout << endl;
		}
	}
}

// hàm kiểm tra xem một danh sách thú cưng có rỗng hay không
bool KiemTraRong(DANHSACHTHUCUNG danhSach)
{
	if (danhSach.theDau == NULL && danhSach.theCuoi == NULL)
		return true;
	return false;
}

// thêm một thẻ vào cuối danh sách
void ThemTheVaoCuoiDanhSach(DANHSACHTHUCUNG& danhSach, conTroThe theCanChen)
{
	if (KiemTraRong(danhSach) == true)
		danhSach.theDau = danhSach.theCuoi = theCanChen;
	else
	{
		danhSach.theCuoi->theTiepTheo = theCanChen;
		danhSach.theCuoi = theCanChen;
	}
}

// hàm nhập một danh sách thú cưng
void NhapDanhSachThuCung(DANHSACHTHUCUNG& danhSach)
{
	int soLuongThuCung = 0;
	bool kiemTraNhapSai = false;
	cout << endl;
	cout << "Nhap so luong thu cung muon them vao danh sach: ";
	do
	{
		cin >> soLuongThuCung;
		kiemTraNhapSai = cin.fail();
		if (kiemTraNhapSai || soLuongThuCung <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "SO LUONG khong hop le, nhap lai: ";
		}
	} while (kiemTraNhapSai || soLuongThuCung <= 0);
	// chạy lần lượt từ và lưu từng thẻ chứa thông tin vào danh sách có số lượng vừa tạo
	cout << endl;
	for (int i = 0; i < soLuongThuCung; i++)
	{
		cout << "NHAP THONG TIN CUA THU CUNG THU " << i + danhSach._SoLuong << endl;
		conTroThe theMoi = new TheThuCung;
		NhapThongTinMotThuCung(danhSach, theMoi->thongTin);
		for (int i = 0; i < 60; i++)
			cout << "-";
		cout << endl;
		ThemTheVaoCuoiDanhSach(danhSach, theMoi);
	}
	danhSach._SoLuong += soLuongThuCung;
}

// hàm xóa toàn bộ danh sách
void XoaDanhSach(DANHSACHTHUCUNG& danhSach)
{
	// chỉ xóa khi danh sách có ít nhất một thẻ
	if (KiemTraRong(danhSach) == false)
	{
		while (danhSach.theDau)
		{
			conTroThe theTam = danhSach.theDau;
			danhSach.theDau = danhSach.theDau->theTiepTheo;
			delete theTam;
		}
		danhSach._SoLuong = -1;
		danhSach.theDau = NULL;
		danhSach.theCuoi = NULL;
	}
}

// hàm tìm địa chỉ tới thẻ có mã số
conTroThe TimTheCoMaSo(DANHSACHTHUCUNG danhSach, string maSo)
{
	if (KiemTraRong(danhSach) == true)
		return NULL;
	for (conTroThe theCanTim = danhSach.theDau; theCanTim; theCanTim = theCanTim->theTiepTheo)
		if (theCanTim->thongTin._MaSo == maSo)
			return theCanTim;
	return NULL;
}

void BanThuCung(DANHSACHTHUCUNG& danhSach)
{
	if (KiemTraRong(danhSach) == true)
		cout << "Danh sach thu cung rong." << endl;
	else
	{
		string maSo = "";
		cout << "Nhap ma so thu cung can mua (neu co), day la ma gom 7 ky tu: ";
		getline(cin, maSo);
		// nếu số phần tử của mã số không phải bằng bày hay nó chứa khoảng trắng thì cho người dùng tiếp tục nhập cho đến khi nào nhập đúng
		while (maSo.size() != 7 || coChuaKhoangTrang(maSo) == true)
		{
			cout << "MA SO hop le, nhap lai: ";
			getline(cin, maSo);
		}
		cout << endl;
		conTroThe theCanMua = TimTheCoMaSo(danhSach, maSo);
		if (theCanMua == NULL)
			cout << "==> [The ban nhap khong co trong danh sach.]";
		else
		{
			cout << "==> Co mot thu cung co ma so nhu ban vua nhap." << endl;
			XuatThongTinMotThe(theCanMua->thongTin);
			double giaBan = 100 + (theCanMua->thongTin._KhoiLuong * 2) - theCanMua->thongTin._Tuoi;
			cout << "-- GIA BAN: " << setprecision(3) << giaBan << " USD" << endl;
			cout << "---------------------------" << endl;
			cout << "Nhap y hoac Y de mua, nhap phim khac de huy." << endl;
			cout << "Ban muon: ";
			string lenh;
			cin >> lenh;
			if (lenh == "y" || lenh == "Y")
			{
				cout << endl;
				cout << "Chuc mung ban da mua thanh cong thu cung " << theCanMua->thongTin._Ten << " thanh cong." << endl;
				XoaTheCoDiaChi(danhSach, theCanMua);
			}
			else
			{
				cout << endl;
				cout << "Chuc ban co mot ngay tot lanh." << endl;
				cout << "Thu cung nay van con trong shop." << endl;
				cout << "Ban co the mua no o lan sau, tran trong." << endl;
			}
		}
	}
}

void XoaTheCoDiaChi(DANHSACHTHUCUNG& danhSach, conTroThe theCanXoa)
{
	if (KiemTraRong(danhSach) == true)
		cout << "Danh Sach rong." << endl;
	else
	{
		if (theCanXoa == danhSach.theDau && theCanXoa == danhSach.theCuoi) // trường hợp chỉ có một thẻ
		{
			delete danhSach.theDau;
			danhSach.theDau = danhSach.theCuoi = NULL;
		}
		else if (theCanXoa == danhSach.theDau) // thẻ cần xóa ở đầu danh sách
		{
			danhSach.theDau = danhSach.theDau->theTiepTheo;
			delete theCanXoa;
		}
		else if (theCanXoa == danhSach.theCuoi) // thẻ cần xóa ở cuối danh sách
		{
			conTroThe p = danhSach.theDau;
			while (p->theTiepTheo != danhSach.theCuoi)
			{
				p = p->theTiepTheo;
			}
			danhSach.theCuoi = p;
			p->theTiepTheo = NULL;
			delete theCanXoa;
		}
		else // ở những vị trí còn lại
		{
			conTroThe r = theCanXoa->theTiepTheo;
			*theCanXoa = *r;
			if (r == danhSach.theCuoi)
				danhSach.theCuoi = theCanXoa;
			delete r;
		}
		danhSach._SoLuong -= 1;
	}
}

// hàm này giúp thay dổi màu long củ thú cưng nếu mà số người dùng nhập là một số hợp lệ
void CapNhatMauLong(DANHSACHTHUCUNG& danhSach)
{
	if (KiemTraRong(danhSach) == true)
		cout << "Danh thu cung sach rong." << endl;
	else
	{
		string maSo = "";
		cout << "Nhap ma so thu cung can cap nhat mau long (neu co), day la ma gom 7 ky tu: ";
		getline(cin, maSo);
		// nếu số phần tử của mã số không phải bằng bày hay nó chứa khoảng trắng thì cho người dùng tiếp tục nhập cho đến khi nào nhập đúng
		while (maSo.size() != 7 || coChuaKhoangTrang(maSo) == true)
		{
			cout << "MA SO hop le, nhap lai: ";
			getline(cin, maSo);
		}
		conTroThe theCanMua = TimTheCoMaSo(danhSach, maSo);
		if (theCanMua == NULL)
			cout << endl << "==> [KHONG CO THU CUNG CO MA SO BAN VUA NHAP]" << endl;
		else
		{
			cout << endl << "Co mot thu cung co ma so: " << theCanMua->thongTin._MaSo << endl;
			XuatThongTinMotThe(theCanMua->thongTin);
			cout << endl << "Nhap mau sac muon thay doi cua thu cung (vang, nau, trang, den, xam): ";
			string bienNhapTam = "";
			getline(cin, bienNhapTam);
			// nếu không phải các màu vàng, nâu, trang, den hoặc xám thì nhập lại
			while (!(bienNhapTam == "vang" || bienNhapTam == "nau" || bienNhapTam == "trang" || bienNhapTam == "den" || bienNhapTam == "xam"))
			{
				cout << "MAU SAC khong hop le, vui long nhap lai: ";
				getline(cin, bienNhapTam);
			}
			theCanMua->thongTin._MauSac = bienNhapTam;
			cout << endl << "==> [BAN DA CAP NHAT MAU LONG CHO THU CUNG " << bienNhapTam << " THANH CONG]" << endl;
		}
	}
}

// hàm thê một thú cưng tại môt vị trí cho trước
void ThemMotThe(DANHSACHTHUCUNG& danhSach)
{
	int viTri;
	cout << "Vi tri hop le phai lon hon hoac bang 0 va nho hon hoac bang " << danhSach._SoLuong << endl;
	cout << "Vui long nhap vi tri: ";
	bool kiemTraNhapSai = false;
	do
	{
		cin >> viTri;
		kiemTraNhapSai = cin.fail();
		if (kiemTraNhapSai == true)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Vi tri ban nhap khong hop le, nhap lai: ";
		}
	} while (kiemTraNhapSai == true);
	if (viTri < 0 || viTri > danhSach._SoLuong)
	{
		cout << "VI TRI ban nhap khong hop le, cho lenh so 5 de thuc hien lai." << endl;
		return;
	}
	cout << endl;
	cout << "Nhap thong tin thu cung can them vao danh sach: " << endl;
	conTroThe theMoi = new TheThuCung;
	NhapThongTinMotThuCung(danhSach, theMoi->thongTin);
	// nếu vị trí = 0 thì thêm ở đầu
	if (viTri == 0)
	{
		if (KiemTraRong(danhSach) == true)
		{
			danhSach.theDau = danhSach.theCuoi = theMoi;
		}
		else
		{
			theMoi->theTiepTheo = danhSach.theDau;
			danhSach.theDau = theMoi;
		}
	}
	else if (viTri == danhSach._SoLuong) // thêm vào cuối
	{
		if (KiemTraRong(danhSach) == true)
		{
			danhSach.theDau = danhSach.theCuoi = theMoi;
		}
		else
		{
			danhSach.theCuoi->theTiepTheo = theMoi;
			danhSach.theCuoi = theMoi;
		}
	}
	// tìm thẻ hiện tại tại vị trí cần thêm
	else
	{
		int i = 0;
		conTroThe p = danhSach.theDau;
		while (i < viTri - 1)
		{
			i += 1;
			p = p->theTiepTheo;
		}
		theMoi->theTiepTheo = p->theTiepTheo;
		p->theTiepTheo = theMoi;
	}
	danhSach._SoLuong += 1;
	cout << endl;
	for (int i = 0; i < 60; i++)
		cout << "-";
	cout << endl << "==> [BAN DA THEM THANH CONG THU CUNG NAY VAO DANH SACH O VI TRI " << viTri << " THANH CONG]" << endl;
}

// hàm xóa đồng loạt các thú cưng có trọng lượng lớn hơn ngưỡng K
void XoaTheCoTrongLuongLonHonNguong(DANHSACHTHUCUNG& danhSach)
{
	if (KiemTraRong(danhSach) == true)
		cout << "Danh sach rong." << endl;
	else
	{
		double nguongK;
		cout << "Moi ban nhap nguong khoi luong K: ";
		bool kiemTraNhapSai = false;
		do
		{
			cin >> nguongK;
			kiemTraNhapSai = cin.fail();
			if (kiemTraNhapSai == true || nguongK <= 0)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Nhap nguong khong hop le, nhap lai: ";
			}

		} while (kiemTraNhapSai || nguongK <= 0);
		// xóa các thẻ có khối lượng lớn hơn thẻ.
		bool coBiXoa = false;
		conTroThe p = danhSach.theDau;
		while (p)
		{
			if (p->thongTin._KhoiLuong > nguongK)
			{
				cout << endl << "Thu cung co thong tin" << endl;
				XuatThongTinMotThe(p->thongTin);
				conTroThe theCanXoa = p;
				p = p->theTiepTheo;
				XoaTheCoDiaChi(danhSach, theCanXoa);
				if (p != NULL && p != danhSach.theCuoi)
					p = theCanXoa;
				coBiXoa = true;
			}
			else
				p = p->theTiepTheo;
		}
		cout << endl;
		if (coBiXoa == true)
			cout << "==> [THU CUNG TREN DUOC XOA KHOI DANH SACH THANH CONG]" << endl;
		else
			cout << "==> [KHONG CO THU CUNG	CO KHOI LUONG LON HON " << nguongK << "]" << endl;
	}
}

int menu()
{
	cout << endl << endl;
	cout << "------------------------------MENU------------------------------" << endl;
	cout << " 1. Khoi tao danh sach rong." << endl;
	cout << " 2. Nhap danh sach thu cung. " << endl;
	cout << " 3. In danh sach thu cung." << endl;
	cout << " 4. Ban thu cung." << endl;
	cout << " 5. Them thu cung vao mot vi tri trong danh sach." << endl;
	cout << " 6. Cap nhat mau long cho mot thu cung." << endl;
	cout << " 7. Xoa khoi danh sach thu cung co khoi luong lon hon nguong K." << endl;
	cout << " 8. Thoat chung trinh." << endl;
	cout << " ==> [CHUONG TRINH SE TU GIAI PHONG VUNG NHO KHI BAN THOAT]" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Ban muon thuc hien lenh: ";
	return 8;
}

int chonLenh(int soLenh)
{
	int n = 0;
	bool kiemTraNhapSai = false;
	do
	{
		cin >> n;
		kiemTraNhapSai = cin.fail();
		if (kiemTraNhapSai == true || n < 0 || n > soLenh);
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Lenh khong hop le, nhap lai: ";
		}
	} while (kiemTraNhapSai || n < 0 || n > soLenh);
	return n;
}

// chạy menu
void chayMenu(DANHSACHTHUCUNG& danhSach, int lenh)
{
	system("cls");
	cout << endl;
	if (danhSach._SoLuong == -1)
	{
		if (lenh == 1)
		{
			for (int i = 0; i < 35; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG KHOI TAO DANH SACH RONG|" << endl;
			for (int i = 0; i < 35; i++)
				cout << "-";
			cout << endl << endl;
			KhoiTaoDanhSachRong(danhSach);
			cout << "Danh sach thu cung da duoc khoi tao thanh cong." << endl;
		}
		else if (lenh == 8)
			return;
		else
			cout << "Vui long khoi tao danh sach truong khi thuc hien cac chuc nang nay." << endl;
		chayMenu(danhSach, chonLenh(menu()));
	}
	else
	{
		if (lenh == 1)
		{
			for (int i = 0; i < 35; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG KHOI TAO DANH SACH RONG|" << endl;
			for (int i = 0; i < 35; i++)
				cout << "-";
			cout << endl << endl;
			cout << "*Danh sach da duoc khoi tao." << endl;
			cout << "*Neu ban muon tao danh sach moi thi phan du lien cu se bi mat." << endl;
			cout << "--Nhan y hoac Y neu muon khoi tao danh sach moi." << endl;
			cout << "--Nhan phim khac neu khong muon khoi tao." << endl;
			cout << "-------------------" << endl;
			cout << "===> Ban muon: ";
			string xacNhan = "";
			cin >> xacNhan;
			if (xacNhan == "y" || xacNhan == "Y")
			{
				XoaDanhSach(danhSach);
				cout << "Toan bo du lieu cu da duoc xoa." << endl << endl;
				KhoiTaoDanhSachRong(danhSach);
				cout << "Danh sach moi da duoc khoi tao thanh cong." << endl;
			}
			else
				cout << "Thong tin danh sach cu cua ban van con." << endl;
		}
		else if (lenh == 2)
		{
			for (int i = 0; i < 44; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG NHAP THEM VAO DANH SACH THU CUNG|" << endl;
			for (int i = 0; i < 44; i++)
				cout << "-";
			cout << endl << endl;
			NhapDanhSachThuCung(danhSach);
			cout << endl << "Danh sach ban vua nhap duoc luu thanh cong vao danh sach." << endl;
		}
		else if (lenh == 3)
		{
			XuatDanhSachThuCung(danhSach);
		}
		else if (lenh == 4)
		{
			for (int i = 0; i < 28; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG MUA BAN THU CUNG|" << endl;
			for (int i = 0; i < 28; i++)
				cout << "-";
			cout << endl << endl;
			BanThuCung(danhSach);
		}
		else if (lenh == 5)
		{
			for (int i = 0; i < 64; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG THEM MOT THE THU CUNG VAO MOT VI TRI TRONG DANH SACH|" << endl;
			for (int i = 0; i < 64; i++)
				cout << "-";
			cout << endl << endl;
			ThemMotThe(danhSach);
		}
		else if (lenh == 6)
		{
			for (int i = 0; i < 42; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG CAP NHAT MAU LONG CUA THU CUNG|" << endl;
			for (int i = 0; i < 42; i++)
				cout << "-";
			cout << endl << endl;
			CapNhatMauLong(danhSach);
		}
		else if (lenh == 7)
		{
			for (int i = 0; i < 71; i++)
				cout << "-";
			cout << endl;
			cout << "|CHUC NANG XOA TRONG DANH SACH THU CUNG CO KHOI LUONG LON HON NGUONG K|" << endl;
			for (int i = 0; i < 71; i++)
				cout << "-";
			cout << endl << endl;
			XoaTheCoTrongLuongLonHonNguong(danhSach);
		}
		else if (lenh == 8)
			return;
		chayMenu(danhSach, chonLenh(menu()));
	}
}