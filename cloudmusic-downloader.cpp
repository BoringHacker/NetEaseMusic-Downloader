#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

std::string get(std::string address) {
	int pos = 0, mark = 0, length = address.size();;
	std::string result;
	for (; pos < length; ++pos) {
		if (address[pos] == '=') {
			mark = 1;
			continue;
		}
		if (mark == 1 && !isdigit(address[pos])) break;
		if (mark == 1) {
			result.push_back(address[pos]);
		}
	}
	return result + ".mp3";
}

signed main() {
	std::cout << "music address:(NetEase Music only)\n";
	std::string address, download;
	std::cin >> address;
	download = "http://music.163.com/song/media/outer/url?id=";
	download += get(address);
	ShellExecute(NULL, "open", download.c_str(), NULL, NULL, SW_SHOWNORMAL);
}