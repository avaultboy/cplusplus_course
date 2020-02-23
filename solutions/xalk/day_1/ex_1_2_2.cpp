
#include <iostream>


using namespace std;




int main() {
	int cnt = 0;

	for (int a0 = 0; a0 < 10; a0 ++){
		for (int b1 = 0; b1 < 10; b1++) {
			if (b1 == a0) continue;
			for (int c2 = 0; c2 < 10; c2++){
				if (c2 == b1 || c2 == a0) continue;
				for (int d3 = 0; d3 < 10; d3++){
					if (d3 == c2 || d3 == b1 || d3 == a0) continue;
					for (int e4 = 0; e4 < 10; e4++) {
						if (e4 == d3 || e4 == c2 || e4 == b1 || e4 == a0) continue;
						for (int f5 = 0; f5 < 10; f5++){
							if (f5 == e4 || f5 == d3 || f5 == c2 || f5 == b1 || f5 == a0) continue;
							for (int g6 = 0; g6 < 10; g6++){
								if (g6 == f5 || g6 == e4 || g6 == d3 || g6 == c2 || g6 == b1 || g6 == a0) continue;
								for (int h7 = 0; h7 < 10; h7++){
									if (h7 == g6 || h7 == f5 || h7 == e4 || h7 == d3 || h7 == c2 || h7 == b1 || h7 == a0) continue;
									for (int i8 = 0; i8 < 10; i8++) {
										if (i8 == h7 || i8 == g6 || i8 == f5 || i8 == e4 || i8 == d3 || i8 == c2 || i8 == b1 || i8 == a0) continue;
										for (int j9 = 0; j9 < 10; j9++){
											if (j9 == i8 || j9 == h7 || j9 == g6 || j9 == f5 || j9 == e4 || j9 == d3 || j9 == c2 || j9 == b1 || j9 == a0) continue;
											if (++cnt == 100000){
												cout << a0 << b1 << c2 << d3 << e4 << f5 << g6 << h7 << i8 << j9 << endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
