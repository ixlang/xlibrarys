/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Fri Jan 27 16:11:27 EST 2017 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 15 -name t1bv_15 -include t1b.h -sign 1 */

/*
 * This function contains 92 FP additions, 77 FP multiplications,
 * (or, 50 additions, 35 multiplications, 42 fused multiply/add),
 * 81 stack variables, 8 constants, and 30 memory accesses
 */
#include "t1b.h"

static void t1bv_15(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP823639103, +0.823639103546331925877420039278190003029660514);
     DVK(KP910592997, +0.910592997310029334643087372129977886038870291);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 28)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 28), MAKE_VOLATILE_STRIDE(15, rs)) {
	       V Tq, Ty, Th, TV, TK, Ts, T1f, T7, Tu, TA, TC, Tj, Tk, T1g, Tf;
	       {
		    V T1, T4, T2, T9, Te;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    T4 = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    T2 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    {
			 V T8, Tp, Tx, Tg;
			 T8 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Tp = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tx = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tg = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 {
			      V Tb, Td, Tr, T6, Tt, Tz, TB, Ti;
			      {
				   V T5, T3, Ta, Tc;
				   Ta = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
				   Tc = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
				   T5 = BYTW(&(W[TWVL * 18]), T4);
				   T3 = BYTW(&(W[TWVL * 8]), T2);
				   T9 = BYTW(&(W[TWVL * 4]), T8);
				   Tq = BYTW(&(W[TWVL * 10]), Tp);
				   Ty = BYTW(&(W[TWVL * 16]), Tx);
				   Th = BYTW(&(W[TWVL * 22]), Tg);
				   Tb = BYTW(&(W[TWVL * 14]), Ta);
				   Td = BYTW(&(W[TWVL * 24]), Tc);
				   Tr = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
				   TV = VSUB(T3, T5);
				   T6 = VADD(T3, T5);
				   Tt = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			      }
			      Tz = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			      TB = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			      Ti = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			      Te = VADD(Tb, Td);
			      TK = VSUB(Tb, Td);
			      Ts = BYTW(&(W[TWVL * 20]), Tr);
			      T1f = VADD(T1, T6);
			      T7 = VFNMS(LDK(KP500000000), T6, T1);
			      Tu = BYTW(&(W[0]), Tt);
			      TA = BYTW(&(W[TWVL * 26]), Tz);
			      TC = BYTW(&(W[TWVL * 6]), TB);
			      Tj = BYTW(&(W[TWVL * 2]), Ti);
			      Tk = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 }
		    }
		    T1g = VADD(T9, Te);
		    Tf = VFNMS(LDK(KP500000000), Te, T9);
	       }
	       {
		    V Tv, TN, TD, TO, Tl;
		    Tv = VADD(Ts, Tu);
		    TN = VSUB(Ts, Tu);
		    TD = VADD(TA, TC);
		    TO = VSUB(TA, TC);
		    Tl = BYTW(&(W[TWVL * 12]), Tk);
		    {
			 V Tw, T1j, TX, TP, TE, T1k, TL, Tm;
			 Tw = VFNMS(LDK(KP500000000), Tv, Tq);
			 T1j = VADD(Tq, Tv);
			 TX = VADD(TN, TO);
			 TP = VSUB(TN, TO);
			 TE = VFNMS(LDK(KP500000000), TD, Ty);
			 T1k = VADD(Ty, TD);
			 TL = VSUB(Tj, Tl);
			 Tm = VADD(Tj, Tl);
			 {
			      V TT, TF, T1q, T1l, TW, TM, T1h, Tn;
			      TT = VSUB(Tw, TE);
			      TF = VADD(Tw, TE);
			      T1q = VSUB(T1j, T1k);
			      T1l = VADD(T1j, T1k);
			      TW = VADD(TK, TL);
			      TM = VSUB(TK, TL);
			      T1h = VADD(Th, Tm);
			      Tn = VFNMS(LDK(KP500000000), Tm, Th);
			      {
				   V T10, TY, T16, TQ, T1r, T1i, TS, To, TZ, T1e;
				   T10 = VSUB(TW, TX);
				   TY = VADD(TW, TX);
				   T16 = VFNMS(LDK(KP618033988), TM, TP);
				   TQ = VFMA(LDK(KP618033988), TP, TM);
				   T1r = VSUB(T1g, T1h);
				   T1i = VADD(T1g, T1h);
				   TS = VSUB(Tf, Tn);
				   To = VADD(Tf, Tn);
				   TZ = VFNMS(LDK(KP250000000), TY, TV);
				   T1e = VMUL(LDK(KP866025403), VADD(TV, TY));
				   {
					V T1u, T1s, T1o, T18, TU, TG, TI, T19, T11, T1n, T1m;
					T1u = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1q, T1r));
					T1s = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1r, T1q));
					T1m = VADD(T1i, T1l);
					T1o = VSUB(T1i, T1l);
					T18 = VFNMS(LDK(KP618033988), TS, TT);
					TU = VFMA(LDK(KP618033988), TT, TS);
					TG = VADD(To, TF);
					TI = VSUB(To, TF);
					T19 = VFNMS(LDK(KP559016994), T10, TZ);
					T11 = VFMA(LDK(KP559016994), T10, TZ);
					ST(&(x[0]), VADD(T1f, T1m), ms, &(x[0]));
					T1n = VFNMS(LDK(KP250000000), T1m, T1f);
					{
					     V T1a, T1c, T14, T12, T1p, T1t, T15, TJ, T1d, TH;
					     T1d = VADD(T7, TG);
					     TH = VFNMS(LDK(KP250000000), TG, T7);
					     T1a = VMUL(LDK(KP951056516), VFMA(LDK(KP910592997), T19, T18));
					     T1c = VMUL(LDK(KP951056516), VFNMS(LDK(KP910592997), T19, T18));
					     T14 = VMUL(LDK(KP951056516), VFNMS(LDK(KP910592997), T11, TU));
					     T12 = VMUL(LDK(KP951056516), VFMA(LDK(KP910592997), T11, TU));
					     T1p = VFNMS(LDK(KP559016994), T1o, T1n);
					     T1t = VFMA(LDK(KP559016994), T1o, T1n);
					     ST(&(x[WS(rs, 10)]), VFMAI(T1e, T1d), ms, &(x[0]));
					     ST(&(x[WS(rs, 5)]), VFNMSI(T1e, T1d), ms, &(x[WS(rs, 1)]));
					     T15 = VFNMS(LDK(KP559016994), TI, TH);
					     TJ = VFMA(LDK(KP559016994), TI, TH);
					     {
						  V T17, T1b, T13, TR;
						  ST(&(x[WS(rs, 12)]), VFNMSI(T1s, T1p), ms, &(x[0]));
						  ST(&(x[WS(rs, 3)]), VFMAI(T1s, T1p), ms, &(x[WS(rs, 1)]));
						  ST(&(x[WS(rs, 9)]), VFNMSI(T1u, T1t), ms, &(x[WS(rs, 1)]));
						  ST(&(x[WS(rs, 6)]), VFMAI(T1u, T1t), ms, &(x[0]));
						  T17 = VFNMS(LDK(KP823639103), T16, T15);
						  T1b = VFMA(LDK(KP823639103), T16, T15);
						  T13 = VFMA(LDK(KP823639103), TQ, TJ);
						  TR = VFNMS(LDK(KP823639103), TQ, TJ);
						  ST(&(x[WS(rs, 13)]), VFMAI(T1a, T17), ms, &(x[WS(rs, 1)]));
						  ST(&(x[WS(rs, 2)]), VFNMSI(T1a, T17), ms, &(x[0]));
						  ST(&(x[WS(rs, 8)]), VFMAI(T1c, T1b), ms, &(x[0]));
						  ST(&(x[WS(rs, 7)]), VFNMSI(T1c, T1b), ms, &(x[WS(rs, 1)]));
						  ST(&(x[WS(rs, 11)]), VFMAI(T14, T13), ms, &(x[WS(rs, 1)]));
						  ST(&(x[WS(rs, 4)]), VFNMSI(T14, T13), ms, &(x[0]));
						  ST(&(x[WS(rs, 14)]), VFNMSI(T12, TR), ms, &(x[0]));
						  ST(&(x[WS(rs, 1)]), VFMAI(T12, TR), ms, &(x[WS(rs, 1)]));
					     }
					}
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 15, XSIMD_STRING("t1bv_15"), twinstr, &GENUS, {50, 35, 42, 0}, 0, 0, 0 };

void XSIMD(codelet_t1bv_15) (planner *p) {
     X(kdft_dit_register) (p, t1bv_15, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 15 -name t1bv_15 -include t1b.h -sign 1 */

/*
 * This function contains 92 FP additions, 53 FP multiplications,
 * (or, 78 additions, 39 multiplications, 14 fused multiply/add),
 * 52 stack variables, 10 constants, and 30 memory accesses
 */
#include "t1b.h"

static void t1bv_15(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP216506350, +0.216506350946109661690930792688234045867850657);
     DVK(KP484122918, +0.484122918275927110647408174972799951354115213);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP509036960, +0.509036960455127183450980863393907648510733164);
     DVK(KP823639103, +0.823639103546331925877420039278190003029660514);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 28)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 28), MAKE_VOLATILE_STRIDE(15, rs)) {
	       V Ts, TV, T1f, TZ, T10, Tb, Tm, Tt, T1j, T1k, T1l, TI, TM, TR, Tz;
	       V TD, TQ, T1g, T1h, T1i;
	       {
		    V TT, Tr, Tp, Tq, To, TU;
		    TT = LD(&(x[0]), ms, &(x[0]));
		    Tq = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
		    Tr = BYTW(&(W[TWVL * 18]), Tq);
		    To = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Tp = BYTW(&(W[TWVL * 8]), To);
		    Ts = VSUB(Tp, Tr);
		    TU = VADD(Tp, Tr);
		    TV = VFNMS(LDK(KP500000000), TU, TT);
		    T1f = VADD(TT, TU);
	       }
	       {
		    V Tx, TG, TK, TB, T5, Ty, Tg, TH, Tl, TL, Ta, TC;
		    {
			 V Tw, TF, TJ, TA;
			 Tw = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Tx = BYTW(&(W[TWVL * 4]), Tw);
			 TF = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 TG = BYTW(&(W[TWVL * 10]), TF);
			 TJ = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 TK = BYTW(&(W[TWVL * 16]), TJ);
			 TA = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 TB = BYTW(&(W[TWVL * 22]), TA);
		    }
		    {
			 V T2, T4, T1, T3;
			 T1 = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 T2 = BYTW(&(W[TWVL * 14]), T1);
			 T3 = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 T4 = BYTW(&(W[TWVL * 24]), T3);
			 T5 = VSUB(T2, T4);
			 Ty = VADD(T2, T4);
		    }
		    {
			 V Td, Tf, Tc, Te;
			 Tc = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 Td = BYTW(&(W[TWVL * 20]), Tc);
			 Te = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 Tf = BYTW(&(W[0]), Te);
			 Tg = VSUB(Td, Tf);
			 TH = VADD(Td, Tf);
		    }
		    {
			 V Ti, Tk, Th, Tj;
			 Th = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 Ti = BYTW(&(W[TWVL * 26]), Th);
			 Tj = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 Tk = BYTW(&(W[TWVL * 6]), Tj);
			 Tl = VSUB(Ti, Tk);
			 TL = VADD(Ti, Tk);
		    }
		    {
			 V T7, T9, T6, T8;
			 T6 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 T7 = BYTW(&(W[TWVL * 2]), T6);
			 T8 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 T9 = BYTW(&(W[TWVL * 12]), T8);
			 Ta = VSUB(T7, T9);
			 TC = VADD(T7, T9);
		    }
		    TZ = VSUB(T5, Ta);
		    T10 = VSUB(Tg, Tl);
		    Tb = VADD(T5, Ta);
		    Tm = VADD(Tg, Tl);
		    Tt = VADD(Tb, Tm);
		    T1j = VADD(TG, TH);
		    T1k = VADD(TK, TL);
		    T1l = VADD(T1j, T1k);
		    TI = VFNMS(LDK(KP500000000), TH, TG);
		    TM = VFNMS(LDK(KP500000000), TL, TK);
		    TR = VADD(TI, TM);
		    Tz = VFNMS(LDK(KP500000000), Ty, Tx);
		    TD = VFNMS(LDK(KP500000000), TC, TB);
		    TQ = VADD(Tz, TD);
		    T1g = VADD(Tx, Ty);
		    T1h = VADD(TB, TC);
		    T1i = VADD(T1g, T1h);
	       }
	       {
		    V T1o, T1m, T1n, T1s, T1t, T1q, T1r, T1u, T1p;
		    T1o = VMUL(LDK(KP559016994), VSUB(T1i, T1l));
		    T1m = VADD(T1i, T1l);
		    T1n = VFNMS(LDK(KP250000000), T1m, T1f);
		    T1q = VSUB(T1g, T1h);
		    T1r = VSUB(T1j, T1k);
		    T1s = VBYI(VFNMS(LDK(KP951056516), T1r, VMUL(LDK(KP587785252), T1q)));
		    T1t = VBYI(VFMA(LDK(KP951056516), T1q, VMUL(LDK(KP587785252), T1r)));
		    ST(&(x[0]), VADD(T1f, T1m), ms, &(x[0]));
		    T1u = VADD(T1o, T1n);
		    ST(&(x[WS(rs, 6)]), VADD(T1t, T1u), ms, &(x[0]));
		    ST(&(x[WS(rs, 9)]), VSUB(T1u, T1t), ms, &(x[WS(rs, 1)]));
		    T1p = VSUB(T1n, T1o);
		    ST(&(x[WS(rs, 3)]), VSUB(T1p, T1s), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 12)]), VADD(T1s, T1p), ms, &(x[0]));
	       }
	       {
		    V T11, T18, T1e, TO, T16, Tv, T15, TY, T1d, T19, TE, TN;
		    T11 = VFMA(LDK(KP823639103), TZ, VMUL(LDK(KP509036960), T10));
		    T18 = VFNMS(LDK(KP823639103), T10, VMUL(LDK(KP509036960), TZ));
		    T1e = VBYI(VMUL(LDK(KP866025403), VADD(Ts, Tt)));
		    TE = VSUB(Tz, TD);
		    TN = VSUB(TI, TM);
		    TO = VFMA(LDK(KP951056516), TE, VMUL(LDK(KP587785252), TN));
		    T16 = VFNMS(LDK(KP951056516), TN, VMUL(LDK(KP587785252), TE));
		    {
			 V Tn, Tu, TS, TW, TX;
			 Tn = VMUL(LDK(KP484122918), VSUB(Tb, Tm));
			 Tu = VFNMS(LDK(KP216506350), Tt, VMUL(LDK(KP866025403), Ts));
			 Tv = VADD(Tn, Tu);
			 T15 = VSUB(Tn, Tu);
			 TS = VMUL(LDK(KP559016994), VSUB(TQ, TR));
			 TW = VADD(TQ, TR);
			 TX = VFNMS(LDK(KP250000000), TW, TV);
			 TY = VADD(TS, TX);
			 T1d = VADD(TV, TW);
			 T19 = VSUB(TX, TS);
		    }
		    {
			 V TP, T12, T1b, T1c;
			 ST(&(x[WS(rs, 5)]), VSUB(T1d, T1e), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 10)]), VADD(T1e, T1d), ms, &(x[0]));
			 TP = VBYI(VADD(Tv, TO));
			 T12 = VSUB(TY, T11);
			 ST(&(x[WS(rs, 1)]), VADD(TP, T12), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 14)]), VSUB(T12, TP), ms, &(x[0]));
			 T1b = VBYI(VSUB(T16, T15));
			 T1c = VSUB(T19, T18);
			 ST(&(x[WS(rs, 7)]), VADD(T1b, T1c), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 8)]), VSUB(T1c, T1b), ms, &(x[0]));
			 {
			      V T17, T1a, T13, T14;
			      T17 = VBYI(VADD(T15, T16));
			      T1a = VADD(T18, T19);
			      ST(&(x[WS(rs, 2)]), VADD(T17, T1a), ms, &(x[0]));
			      ST(&(x[WS(rs, 13)]), VSUB(T1a, T17), ms, &(x[WS(rs, 1)]));
			      T13 = VBYI(VSUB(Tv, TO));
			      T14 = VADD(T11, TY);
			      ST(&(x[WS(rs, 4)]), VADD(T13, T14), ms, &(x[0]));
			      ST(&(x[WS(rs, 11)]), VSUB(T14, T13), ms, &(x[WS(rs, 1)]));
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 15, XSIMD_STRING("t1bv_15"), twinstr, &GENUS, {78, 39, 14, 0}, 0, 0, 0 };

void XSIMD(codelet_t1bv_15) (planner *p) {
     X(kdft_dit_register) (p, t1bv_15, &desc);
}
#endif				/* HAVE_FMA */
