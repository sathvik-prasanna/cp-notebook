/**
 * Description: Fast input and output for integers and strings. For doubles, read them
 * as strings and convert them to double using \texttt{stod}.
 * Time: input is $\sim$300ms faster for $10^6$ long longs on CF.
 * Source: 
 	* https://codeforces.com/gym/102394/submission/64154785
 	* https://codeforces.com/contest/1254/submission/65420506 (neal)
 	* https://codeforces.com/blog/entry/45835 (AI.Cash)
 	* https://codeforces.com/blog/entry/93706 (double input)
 * Verification: https://codeforces.com/gym/102394/problem/G 
 * Usage: initO(); int a,b; ri(a,b); wi(b,'\textbackslash n'); wi(a,'\textbackslash n'); 
 */

inline namespace FastIO {

const int BSZ = 1<<15; ////// INPUT
char ibuf[BSZ]; int ipos, ilen;
char nc() { // next char
	if (ipos == ilen) {
		ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
		if (!ilen) return EOF;
	}
	return ibuf[ipos++];
}
void rs(str& x) { // read str
	char ch; while (isspace(ch = nc()));
	do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
}
tcT> void ri(T& x) { // read int or ll
	char ch; int sgn = 1;
	while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
	x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
	x *= sgn;
}
tcT, class... Ts> void ri(T& t, Ts&... ts) { 
	ri(t); ri(ts...); } // read ints
////// OUTPUT (call initO() at start)
char obuf[BSZ], numBuf[100]; int opos;
void flushOut() { fwrite(obuf,1,opos,stdout); opos = 0; }
void wc(char c) { // write char
	if (opos == BSZ) flushOut();
	obuf[opos++] = c; }
void ws(str s) { each(c,s) wc(c); } // write str
tcT> void wi(T x, char after = '\0') { /// write int
	if (x < 0) wc('-'), x *= -1;
	int len = 0; for (;x>=10;x/=10) numBuf[len++] = '0'+(x%10);
	wc('0'+x); R0F(i,len) wc(numBuf[i]);
	if (after) wc(after);
}
void initO() { assert(atexit(flushOut) == 0); } /// auto-flush output

}