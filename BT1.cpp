#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <exception>

using namespace std;


bool checkbinum(wstring binum)
{
    bool checkbinum;
    for (int i = 0; i < binum.length(); i++)
    {
        if (binum[i] != '1' && binum[i] != '0')
        {
            checkbinum = false;
            break;
        }
        else
        {
            checkbinum = true;
        }
    }
    return checkbinum;
}

bool checkhexnum(wstring hexnum)
{
    bool checkhexnum;
    char upchar;
    if (hexnum.length() > 15)
    {
        return checkhexnum = false;
    }
    for (int i = 0; i < hexnum.length(); i++)
    {
        upchar = toupper(hexnum[i]);
        if (upchar != '0' && upchar != '1' && upchar != '2' && upchar != '3'
            && upchar != '4' && upchar != '5' && upchar != '6' && upchar != '7'
            && upchar != '8' && upchar != '9' && upchar != 'A' && upchar != 'B'
            && upchar != 'C' && upchar != 'D' && upchar != 'E' && upchar != 'F')
        {
            checkhexnum = false;
            break;
        }
        else
        {
            checkhexnum = true;
        }
    }
    return checkhexnum;
}

bool checkdecnum(const wstring& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

wstring dec2bi(unsigned long long decnum)
{
    vector<char> mang;
    int i = 0;
    while (decnum > 0)
    {
        if (decnum % 2 == 0)
        {
            mang.push_back('0');
        }
        else
        {
            mang.push_back('1');
        }
        i++;
        decnum /= 2;
    }
    wstring resultdec2bi;
    for (int j = mang.size() - 1; j >= 0; j--)
    {
        resultdec2bi.push_back(mang.at(j));
    }
    return resultdec2bi;
}

wstring dec2hex(unsigned long long decnum)
{
    vector<char> mang;
    int i = 0;
    while (decnum > 0)
    {
        switch (decnum % 16)
        {
        case 0: mang.push_back('0');
            break;
        case 1: mang.push_back('1');
            break;
        case 2: mang.push_back('2');
            break;
        case 3: mang.push_back('3');
            break;
        case 4: mang.push_back('4');
            break;
        case 5: mang.push_back('5');
            break;
        case 6: mang.push_back('6');
            break;
        case 7: mang.push_back('7');
            break;
        case 8: mang.push_back('8');
            break;
        case 9: mang.push_back('9');
            break;
        case 10: mang.push_back('A');
            break;
        case 11: mang.push_back('B');
            break;
        case 12: mang.push_back('C');
            break;
        case 13: mang.push_back('D');
            break;
        case 14: mang.push_back('E');
            break;
        case 15: mang.push_back('F');
            break;
        }
        i++;
        decnum /= 16;
    }
    wstring resultdec2hex;
    for (int j = mang.size() - 1; j >= 0; j--)
    {
        resultdec2hex.push_back(mang.at(j));
    }
    return resultdec2hex;
}

unsigned long long hex2dec(wstring hexnum)
{
    int i = 0;
    int sodenhan = 1;
    long long result = 0;
    for (int i = 0; i < hexnum.length(); i++)
    {
        char upchar = toupper(hexnum[i]);
        switch (upchar)
        {
        case '0': sodenhan = 0;
            break;
        case '1': sodenhan = 1;
            break;
        case '2': sodenhan = 2;
            break;
        case '3': sodenhan = 3;
            break;
        case '4': sodenhan = 4;
            break;
        case '5': sodenhan = 5;
            break;
        case '6': sodenhan = 6;
            break;
        case '7': sodenhan = 7;
            break;
        case '8': sodenhan = 8;
            break;
        case '9': sodenhan = 9;
            break;
        case 'A': sodenhan = 10;
            break;
        case 'B': sodenhan = 11;
            break;
        case 'C': sodenhan = 12;
            break;
        case 'D': sodenhan = 13;
            break;
        case 'E': sodenhan = 14;
            break;
        case 'F': sodenhan = 15;
            break;
        }
        result += (sodenhan * pow(16.0, double(hexnum.length() - 1 - i)));
    }
    return result;
}



unsigned long long bi2dec(wstring binum)
{
    unsigned long long dec_value = 0;
    long double kq = 0;
    unsigned long long kqluythua[66];
    for (int i = 0; i < 66; i++)
    {
        kqluythua[i] = 0;
    }
    for (int i = binum.length()-1; i >= 0; i--)
    {
        if (binum[binum.length()-1-i] == L'1')
        {
            kq = pow(2.0, double(i));
            kqluythua[i] = kq;
        }
    }
    for (int i = 0; i < 66; i++)
    {
        if (kqluythua[i] != 0)
        {
            dec_value += kqluythua[i];
        }
    }
    return dec_value;
}

wstring bi2hex(wstring binum)
{
    wstring resultbi2hex;
    resultbi2hex = dec2hex(bi2dec(binum));
    return resultbi2hex;

}

void menu()
{
    wstring str;
    wcout << L"----*----*----*----\nNhập số tương ứng với từng loại chuyển đổi:\n[1] Hệ 10 sang hệ 2\n[2] Hệ 10 sang hệ 16\n[3] Hệ 2 sang hệ 10\n[4] Hệ 16 sang hệ 10\n[5] Hệ 2 sang hệ 16\n----*----*----*----\nNhập số bạn chọn: ";
    wcin >> str;
    while (str != L"1" && str != L"2" && str != L"3" && str != L"4" && str != L"5")
    {
        wcin.clear();
        wcin.ignore();
        wcout << L"Chỉ được phép nhập ký tự 1-5 tương ứng với từng loại chuyển đổi.\nVui lòng nhập lại: ";
        wcin >> str;
    }
    int choice = stoi(str);
    switch (choice)
    {
    case 1:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ hệ 10 sang hệ 2.\nHãy nhập số bạn muốn chuyển đổi: ";
        wstring strnum1;
        unsigned long long num1;
        wcin >> strnum1;
        while (1)
        {
            if (checkdecnum(strnum1) == false)
            {
                wcout << L"Bạn đã nhập sai định dạng số thập phân, chỉ được phép chứa ký tự 1-9.\nVui lòng nhập lại số cần chuyển đổi: ";
                wcin.clear();
                wcin.ignore();
                wcin >> strnum1;
            }
            else
            {
                try {
                    num1 = stoull(strnum1);
                    break;
                }
                catch (const std::exception& e)
                {
                    wcout << L"Số bạn vừa nhập lớn hơn phạm vi kiểu dữ liệu unsigned long long (từ 0 đến 18446744073709551615).\nVui lòng nhập lại số cần chuyển đổi: ";
                    wcin.clear();
                    wcin.ignore();
                    wcin >> strnum1;
                }
            }
        }
        wcout << L"Kết quả chuyển đổi " << strnum1 << L" ở hệ 10 sang hệ 2 là: " << dec2bi(num1) << endl;
    }
    break;
    case 2:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ hệ 10 sang hệ 16.\nHãy nhập số bạn muốn chuyển đổi: ";
        wstring strnum2;
        unsigned long long num2;
        wcin >> strnum2;
        while (1)
        {
            if (checkdecnum(strnum2) == false)
            {
                wcout << L"Bạn đã nhập sai định dạng số thập phân, chỉ được phép chứa ký tự 1-9.\nVui lòng nhập lại số cần chuyển đổi: ";
                wcin.clear();
                wcin.ignore();
                wcin >> strnum2;
            }
            else
            {
                try {
                    num2 = stoull(strnum2);
                    break;
                }
                catch (const std::exception& e)
                {
                    wcout << L"Số bạn vừa nhập lớn hơn phạm vi kiểu dữ liệu unsigned long long (từ 0 đến 18446744073709551615).\nVui lòng nhập lại số cần chuyển đổi: ";
                    wcin.clear();
                    wcin.ignore();
                    wcin >> strnum2;
                }
            }
        }
        wcout << L"Kết quả chuyển đổi " << strnum2 << L" ở hệ 10 sang hệ 16 là: " << dec2hex(num2) << endl;
    }
        break;
    case 3:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ hệ 2 sang hệ 10.\nHãy nhập số bạn muốn chuyển đổi: ";
        wstring num3;
        wcin >> num3;
        while (1)
        {
            if (checkbinum(num3) == false || num3.length() > 64)
            {
                wcout << L"Bạn đã nhập sai định dạng số nhị phân, chỉ được phép chứa ký tự 1 hoặc 0 và không vượt quá 64 ký tự.\nVui lòng nhập lại số bạn muốn chuyển đổi: ";
                wcin >> num3;
            }
            else
            {
                wcout << L"Kết quả chuyển đổi " << num3 << L" ở hệ 2 sang hệ 10 là: " << bi2dec(num3) << endl;
                break;
            }
        }
    }
    break;
    case 4:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ hệ 16 sang hệ 10.\nHãy nhập số bạn muốn chuyển đổi: ";
        wstring num4;
        wcin >> num4;
        while (checkhexnum(num4) == false)
        {
            wcout << L"Bạn đã nhập sai định dạng số thập lục phân, chỉ được phép chứa ký tự từ 1-9 và từ A-F.\nVui lòng nhập lại số bạn muốn chuyển đổi: ";
            wcin >> num4;
        }
        wcout << L"Kết quả chuyển đổi " << num4 << L" ở hệ 16 sang hệ 10 là: " << hex2dec(num4) << endl;
    }
    break;
    case 5:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ hệ 2 sang hệ 16.\nHãy nhập số bạn muốn chuyển đổi: ";
        wstring num5;
        wcin >> num5;
        while (checkbinum(num5) == false)
        {
            wcout << L"Bạn đã nhập sai định dạng số nhị phân, chỉ được phép chứa ký tự 1 hoặc 0.\nVui lòng nhập lại số bạn muốn chuyển đổi: ";
            wcin >> num5;
        }
        wcout << L"Kết quả chuyển đổi " << num5 << L" ở hệ 2 sang hệ 16 là: " << dec2hex(bi2dec(num5)) << endl;
    }
    break;
    }
}

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wstring tieptuc;
    wcout << L"Môn Hệ Thống Máy Tính - Phần khảo sát số nguyên\nTên SV: Huỳnh Anh Khoa\nMSSV: 21880228\nBài tập 1" << endl;
    do {
        menu();
        wcout << L"\n-------------------\nBạn muốn tiếp tục hay kết thúc?\n[0] Tiếp tục\n[Nút khác bất kỳ] Thoát\n-------------------" << std::endl;
        wcin >> tieptuc;
    } while (tieptuc == L"0");

}