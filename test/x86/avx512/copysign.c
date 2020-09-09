/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN copysign

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/copysign.h>

static int
test_simde_x_mm512_copysign_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
   { { SIMDE_FLOAT32_C(   101.85), SIMDE_FLOAT32_C(   638.93), SIMDE_FLOAT32_C(  -988.13), SIMDE_FLOAT32_C(   346.44),
        SIMDE_FLOAT32_C(  -984.29), SIMDE_FLOAT32_C(    33.87), SIMDE_FLOAT32_C(   170.56), SIMDE_FLOAT32_C(   295.52),
        SIMDE_FLOAT32_C(   361.74), SIMDE_FLOAT32_C(  -255.41), SIMDE_FLOAT32_C(  -306.51), SIMDE_FLOAT32_C(  -203.63),
        SIMDE_FLOAT32_C(  -477.65), SIMDE_FLOAT32_C(   156.06), SIMDE_FLOAT32_C(  -273.72), SIMDE_FLOAT32_C(   883.97) },
      { SIMDE_FLOAT32_C(   199.87), SIMDE_FLOAT32_C(  -325.33), SIMDE_FLOAT32_C(  -536.96), SIMDE_FLOAT32_C(  -823.46),
        SIMDE_FLOAT32_C(   717.11), SIMDE_FLOAT32_C(   790.99), SIMDE_FLOAT32_C(   305.34), SIMDE_FLOAT32_C(   374.95),
        SIMDE_FLOAT32_C(  -940.88), SIMDE_FLOAT32_C(  -518.43), SIMDE_FLOAT32_C(   296.03), SIMDE_FLOAT32_C(   464.18),
        SIMDE_FLOAT32_C(   842.36), SIMDE_FLOAT32_C(   732.27), SIMDE_FLOAT32_C(  -231.90), SIMDE_FLOAT32_C(   -55.79) },
      { SIMDE_FLOAT32_C(   101.85), SIMDE_FLOAT32_C(  -638.93), SIMDE_FLOAT32_C(  -988.13), SIMDE_FLOAT32_C(  -346.44),
        SIMDE_FLOAT32_C(   984.29), SIMDE_FLOAT32_C(    33.87), SIMDE_FLOAT32_C(   170.56), SIMDE_FLOAT32_C(   295.52),
        SIMDE_FLOAT32_C(  -361.74), SIMDE_FLOAT32_C(  -255.41), SIMDE_FLOAT32_C(   306.51), SIMDE_FLOAT32_C(   203.63),
        SIMDE_FLOAT32_C(   477.65), SIMDE_FLOAT32_C(   156.06), SIMDE_FLOAT32_C(  -273.72), SIMDE_FLOAT32_C(  -883.97) } },
    { { SIMDE_FLOAT32_C(   371.20), SIMDE_FLOAT32_C(  -220.03), SIMDE_FLOAT32_C(  -709.35), SIMDE_FLOAT32_C(   386.90),
        SIMDE_FLOAT32_C(   813.83), SIMDE_FLOAT32_C(   461.21), SIMDE_FLOAT32_C(  -317.58), SIMDE_FLOAT32_C(   175.57),
        SIMDE_FLOAT32_C(  -794.20), SIMDE_FLOAT32_C(   375.91), SIMDE_FLOAT32_C(   971.94), SIMDE_FLOAT32_C(  -271.85),
        SIMDE_FLOAT32_C(  -468.03), SIMDE_FLOAT32_C(  -301.78), SIMDE_FLOAT32_C(  -387.88), SIMDE_FLOAT32_C(   731.84) },
      { SIMDE_FLOAT32_C(   372.89), SIMDE_FLOAT32_C(    75.16), SIMDE_FLOAT32_C(   908.38), SIMDE_FLOAT32_C(    90.00),
        SIMDE_FLOAT32_C(  -133.86), SIMDE_FLOAT32_C(   213.73), SIMDE_FLOAT32_C(  -535.05), SIMDE_FLOAT32_C(   -74.73),
        SIMDE_FLOAT32_C(   695.30), SIMDE_FLOAT32_C(   760.98), SIMDE_FLOAT32_C(  -610.55), SIMDE_FLOAT32_C(   537.65),
        SIMDE_FLOAT32_C(   493.25), SIMDE_FLOAT32_C(   157.55), SIMDE_FLOAT32_C(  -518.14), SIMDE_FLOAT32_C(  -135.55) },
      { SIMDE_FLOAT32_C(   371.20), SIMDE_FLOAT32_C(   220.03), SIMDE_FLOAT32_C(   709.35), SIMDE_FLOAT32_C(   386.90),
        SIMDE_FLOAT32_C(  -813.83), SIMDE_FLOAT32_C(   461.21), SIMDE_FLOAT32_C(  -317.58), SIMDE_FLOAT32_C(  -175.57),
        SIMDE_FLOAT32_C(   794.20), SIMDE_FLOAT32_C(   375.91), SIMDE_FLOAT32_C(  -971.94), SIMDE_FLOAT32_C(   271.85),
        SIMDE_FLOAT32_C(   468.03), SIMDE_FLOAT32_C(   301.78), SIMDE_FLOAT32_C(  -387.88), SIMDE_FLOAT32_C(  -731.84) } },
    { { SIMDE_FLOAT32_C(   937.51), SIMDE_FLOAT32_C(  -227.49), SIMDE_FLOAT32_C(  -748.65), SIMDE_FLOAT32_C(   751.35),
        SIMDE_FLOAT32_C(  -766.28), SIMDE_FLOAT32_C(   -66.23), SIMDE_FLOAT32_C(   -73.08), SIMDE_FLOAT32_C(  -560.48),
        SIMDE_FLOAT32_C(  -690.32), SIMDE_FLOAT32_C(  -101.14), SIMDE_FLOAT32_C(   167.67), SIMDE_FLOAT32_C(  -158.35),
        SIMDE_FLOAT32_C(   597.08), SIMDE_FLOAT32_C(   779.79), SIMDE_FLOAT32_C(  -426.51), SIMDE_FLOAT32_C(   -30.03) },
      { SIMDE_FLOAT32_C(  -145.05), SIMDE_FLOAT32_C(  -518.13), SIMDE_FLOAT32_C(  -940.03), SIMDE_FLOAT32_C(   721.10),
        SIMDE_FLOAT32_C(   695.60), SIMDE_FLOAT32_C(  -475.08), SIMDE_FLOAT32_C(  -353.64), SIMDE_FLOAT32_C(   390.89),
        SIMDE_FLOAT32_C(  -714.10), SIMDE_FLOAT32_C(    35.81), SIMDE_FLOAT32_C(   -71.46), SIMDE_FLOAT32_C(   779.15),
        SIMDE_FLOAT32_C(  -806.64), SIMDE_FLOAT32_C(   410.40), SIMDE_FLOAT32_C(  -356.40), SIMDE_FLOAT32_C(  -869.13) },
      { SIMDE_FLOAT32_C(  -937.51), SIMDE_FLOAT32_C(  -227.49), SIMDE_FLOAT32_C(  -748.65), SIMDE_FLOAT32_C(   751.35),
        SIMDE_FLOAT32_C(   766.28), SIMDE_FLOAT32_C(   -66.23), SIMDE_FLOAT32_C(   -73.08), SIMDE_FLOAT32_C(   560.48),
        SIMDE_FLOAT32_C(  -690.32), SIMDE_FLOAT32_C(   101.14), SIMDE_FLOAT32_C(  -167.67), SIMDE_FLOAT32_C(   158.35),
        SIMDE_FLOAT32_C(  -597.08), SIMDE_FLOAT32_C(   779.79), SIMDE_FLOAT32_C(  -426.51), SIMDE_FLOAT32_C(   -30.03) } },
    { { SIMDE_FLOAT32_C(  -817.09), SIMDE_FLOAT32_C(  -105.05), SIMDE_FLOAT32_C(   882.22), SIMDE_FLOAT32_C(  -583.37),
        SIMDE_FLOAT32_C(   828.72), SIMDE_FLOAT32_C(  -190.86), SIMDE_FLOAT32_C(  -143.85), SIMDE_FLOAT32_C(  -861.60),
        SIMDE_FLOAT32_C(   708.00), SIMDE_FLOAT32_C(  -976.17), SIMDE_FLOAT32_C(   -19.95), SIMDE_FLOAT32_C(   305.09),
        SIMDE_FLOAT32_C(   803.62), SIMDE_FLOAT32_C(   553.54), SIMDE_FLOAT32_C(  -724.94), SIMDE_FLOAT32_C(  -341.43) },
      { SIMDE_FLOAT32_C(  -964.59), SIMDE_FLOAT32_C(  -664.97), SIMDE_FLOAT32_C(  -620.33), SIMDE_FLOAT32_C(   731.01),
        SIMDE_FLOAT32_C(  -140.05), SIMDE_FLOAT32_C(    26.03), SIMDE_FLOAT32_C(   121.90), SIMDE_FLOAT32_C(   145.85),
        SIMDE_FLOAT32_C(  -938.16), SIMDE_FLOAT32_C(  -949.56), SIMDE_FLOAT32_C(   -75.00), SIMDE_FLOAT32_C(  -744.80),
        SIMDE_FLOAT32_C(   460.85), SIMDE_FLOAT32_C(   568.59), SIMDE_FLOAT32_C(  -613.93), SIMDE_FLOAT32_C(   643.76) },
      { SIMDE_FLOAT32_C(  -817.09), SIMDE_FLOAT32_C(  -105.05), SIMDE_FLOAT32_C(  -882.22), SIMDE_FLOAT32_C(   583.37),
        SIMDE_FLOAT32_C(  -828.72), SIMDE_FLOAT32_C(   190.86), SIMDE_FLOAT32_C(   143.85), SIMDE_FLOAT32_C(   861.60),
        SIMDE_FLOAT32_C(  -708.00), SIMDE_FLOAT32_C(  -976.17), SIMDE_FLOAT32_C(   -19.95), SIMDE_FLOAT32_C(  -305.09),
        SIMDE_FLOAT32_C(   803.62), SIMDE_FLOAT32_C(   553.54), SIMDE_FLOAT32_C(  -724.94), SIMDE_FLOAT32_C(   341.43) } },
    { { SIMDE_FLOAT32_C(  -536.46), SIMDE_FLOAT32_C(  -731.70), SIMDE_FLOAT32_C(  -939.61), SIMDE_FLOAT32_C(  -707.74),
        SIMDE_FLOAT32_C(    77.44), SIMDE_FLOAT32_C(   -83.46), SIMDE_FLOAT32_C(  -569.34), SIMDE_FLOAT32_C(  -214.56),
        SIMDE_FLOAT32_C(   -59.63), SIMDE_FLOAT32_C(   410.72), SIMDE_FLOAT32_C(  -909.47), SIMDE_FLOAT32_C(  -256.01),
        SIMDE_FLOAT32_C(   -35.74), SIMDE_FLOAT32_C(  -634.41), SIMDE_FLOAT32_C(   402.56), SIMDE_FLOAT32_C(    -0.33) },
      { SIMDE_FLOAT32_C(  -299.38), SIMDE_FLOAT32_C(   782.23), SIMDE_FLOAT32_C(  -269.32), SIMDE_FLOAT32_C(   560.57),
        SIMDE_FLOAT32_C(  -191.74), SIMDE_FLOAT32_C(   852.58), SIMDE_FLOAT32_C(  -293.59), SIMDE_FLOAT32_C(  -129.90),
        SIMDE_FLOAT32_C(   903.02), SIMDE_FLOAT32_C(   631.41), SIMDE_FLOAT32_C(   125.30), SIMDE_FLOAT32_C(   363.87),
        SIMDE_FLOAT32_C(   200.00), SIMDE_FLOAT32_C(   511.37), SIMDE_FLOAT32_C(     7.62), SIMDE_FLOAT32_C(   663.54) },
      { SIMDE_FLOAT32_C(  -536.46), SIMDE_FLOAT32_C(   731.70), SIMDE_FLOAT32_C(  -939.61), SIMDE_FLOAT32_C(   707.74),
        SIMDE_FLOAT32_C(   -77.44), SIMDE_FLOAT32_C(    83.46), SIMDE_FLOAT32_C(  -569.34), SIMDE_FLOAT32_C(  -214.56),
        SIMDE_FLOAT32_C(    59.63), SIMDE_FLOAT32_C(   410.72), SIMDE_FLOAT32_C(   909.47), SIMDE_FLOAT32_C(   256.01),
        SIMDE_FLOAT32_C(    35.74), SIMDE_FLOAT32_C(   634.41), SIMDE_FLOAT32_C(   402.56), SIMDE_FLOAT32_C(     0.33) } },
    { { SIMDE_FLOAT32_C(   779.67), SIMDE_FLOAT32_C(    68.01), SIMDE_FLOAT32_C(   955.81), SIMDE_FLOAT32_C(  -142.89),
        SIMDE_FLOAT32_C(   984.55), SIMDE_FLOAT32_C(  -613.53), SIMDE_FLOAT32_C(   642.55), SIMDE_FLOAT32_C(   -75.08),
        SIMDE_FLOAT32_C(   797.19), SIMDE_FLOAT32_C(   733.08), SIMDE_FLOAT32_C(   668.91), SIMDE_FLOAT32_C(  -238.56),
        SIMDE_FLOAT32_C(  -901.34), SIMDE_FLOAT32_C(    71.47), SIMDE_FLOAT32_C(   761.11), SIMDE_FLOAT32_C(  -200.72) },
      { SIMDE_FLOAT32_C(  -146.31), SIMDE_FLOAT32_C(  -508.21), SIMDE_FLOAT32_C(  -640.16), SIMDE_FLOAT32_C(   661.95),
        SIMDE_FLOAT32_C(  -655.63), SIMDE_FLOAT32_C(    66.26), SIMDE_FLOAT32_C(  -467.95), SIMDE_FLOAT32_C(  -752.61),
        SIMDE_FLOAT32_C(  -302.33), SIMDE_FLOAT32_C(   657.35), SIMDE_FLOAT32_C(   611.26), SIMDE_FLOAT32_C(   897.67),
        SIMDE_FLOAT32_C(   168.73), SIMDE_FLOAT32_C(  -381.12), SIMDE_FLOAT32_C(   561.22), SIMDE_FLOAT32_C(   -51.60) },
      { SIMDE_FLOAT32_C(  -779.67), SIMDE_FLOAT32_C(   -68.01), SIMDE_FLOAT32_C(  -955.81), SIMDE_FLOAT32_C(   142.89),
        SIMDE_FLOAT32_C(  -984.55), SIMDE_FLOAT32_C(   613.53), SIMDE_FLOAT32_C(  -642.55), SIMDE_FLOAT32_C(   -75.08),
        SIMDE_FLOAT32_C(  -797.19), SIMDE_FLOAT32_C(   733.08), SIMDE_FLOAT32_C(   668.91), SIMDE_FLOAT32_C(   238.56),
        SIMDE_FLOAT32_C(   901.34), SIMDE_FLOAT32_C(   -71.47), SIMDE_FLOAT32_C(   761.11), SIMDE_FLOAT32_C(  -200.72) } },
    { { SIMDE_FLOAT32_C(   686.89), SIMDE_FLOAT32_C(   517.02), SIMDE_FLOAT32_C(   805.50), SIMDE_FLOAT32_C(   671.44),
        SIMDE_FLOAT32_C(   903.49), SIMDE_FLOAT32_C(   448.05), SIMDE_FLOAT32_C(  -403.64), SIMDE_FLOAT32_C(   700.67),
        SIMDE_FLOAT32_C(   181.13), SIMDE_FLOAT32_C(  -734.74), SIMDE_FLOAT32_C(  -537.88), SIMDE_FLOAT32_C(   279.80),
        SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(  -776.77), SIMDE_FLOAT32_C(  -920.93), SIMDE_FLOAT32_C(  -809.58) },
      { SIMDE_FLOAT32_C(  -284.98), SIMDE_FLOAT32_C(  -561.08), SIMDE_FLOAT32_C(   852.37), SIMDE_FLOAT32_C(    59.39),
        SIMDE_FLOAT32_C(   505.18), SIMDE_FLOAT32_C(  -615.57), SIMDE_FLOAT32_C(   306.78), SIMDE_FLOAT32_C(  -797.15),
        SIMDE_FLOAT32_C(  -958.22), SIMDE_FLOAT32_C(   -81.96), SIMDE_FLOAT32_C(  -899.48), SIMDE_FLOAT32_C(   210.50),
        SIMDE_FLOAT32_C(   536.92), SIMDE_FLOAT32_C(   661.73), SIMDE_FLOAT32_C(  -841.10), SIMDE_FLOAT32_C(   223.81) },
      { SIMDE_FLOAT32_C(  -686.89), SIMDE_FLOAT32_C(  -517.02), SIMDE_FLOAT32_C(   805.50), SIMDE_FLOAT32_C(   671.44),
        SIMDE_FLOAT32_C(   903.49), SIMDE_FLOAT32_C(  -448.05), SIMDE_FLOAT32_C(   403.64), SIMDE_FLOAT32_C(  -700.67),
        SIMDE_FLOAT32_C(  -181.13), SIMDE_FLOAT32_C(  -734.74), SIMDE_FLOAT32_C(  -537.88), SIMDE_FLOAT32_C(   279.80),
        SIMDE_FLOAT32_C(   336.73), SIMDE_FLOAT32_C(   776.77), SIMDE_FLOAT32_C(  -920.93), SIMDE_FLOAT32_C(   809.58) } },
    { { SIMDE_FLOAT32_C(   178.75), SIMDE_FLOAT32_C(   964.40), SIMDE_FLOAT32_C(  -104.75), SIMDE_FLOAT32_C(    82.24),
        SIMDE_FLOAT32_C(   412.46), SIMDE_FLOAT32_C(   491.60), SIMDE_FLOAT32_C(  -217.08), SIMDE_FLOAT32_C(  -406.41),
        SIMDE_FLOAT32_C(   756.86), SIMDE_FLOAT32_C(   245.04), SIMDE_FLOAT32_C(   873.39), SIMDE_FLOAT32_C(    93.59),
        SIMDE_FLOAT32_C(   468.27), SIMDE_FLOAT32_C(   952.46), SIMDE_FLOAT32_C(   284.01), SIMDE_FLOAT32_C(  -816.71) },
      { SIMDE_FLOAT32_C(  -608.62), SIMDE_FLOAT32_C(   136.39), SIMDE_FLOAT32_C(   242.67), SIMDE_FLOAT32_C(   896.56),
        SIMDE_FLOAT32_C(   520.81), SIMDE_FLOAT32_C(  -450.55), SIMDE_FLOAT32_C(  -900.60), SIMDE_FLOAT32_C(   562.59),
        SIMDE_FLOAT32_C(   467.49), SIMDE_FLOAT32_C(  -800.08), SIMDE_FLOAT32_C(  -226.91), SIMDE_FLOAT32_C(     4.40),
        SIMDE_FLOAT32_C(   861.66), SIMDE_FLOAT32_C(   -68.01), SIMDE_FLOAT32_C(  -771.79), SIMDE_FLOAT32_C(    40.41) },
      { SIMDE_FLOAT32_C(  -178.75), SIMDE_FLOAT32_C(   964.40), SIMDE_FLOAT32_C(   104.75), SIMDE_FLOAT32_C(    82.24),
        SIMDE_FLOAT32_C(   412.46), SIMDE_FLOAT32_C(  -491.60), SIMDE_FLOAT32_C(  -217.08), SIMDE_FLOAT32_C(   406.41),
        SIMDE_FLOAT32_C(   756.86), SIMDE_FLOAT32_C(  -245.04), SIMDE_FLOAT32_C(  -873.39), SIMDE_FLOAT32_C(    93.59),
        SIMDE_FLOAT32_C(   468.27), SIMDE_FLOAT32_C(  -952.46), SIMDE_FLOAT32_C(  -284.01), SIMDE_FLOAT32_C(   816.71) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_x_mm512_copysign_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_x_mm512_copysign_ps(a, b);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm512_copysign_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -103.60), SIMDE_FLOAT64_C(   123.45), SIMDE_FLOAT64_C(  -877.34), SIMDE_FLOAT64_C(  -691.14),
        SIMDE_FLOAT64_C(  -384.94), SIMDE_FLOAT64_C(   -94.43), SIMDE_FLOAT64_C(   -97.55), SIMDE_FLOAT64_C(  -628.08) },
      { SIMDE_FLOAT64_C(  -849.39), SIMDE_FLOAT64_C(  -224.16), SIMDE_FLOAT64_C(   465.51), SIMDE_FLOAT64_C(   618.88),
        SIMDE_FLOAT64_C(  -271.70), SIMDE_FLOAT64_C(  -250.47), SIMDE_FLOAT64_C(   802.16), SIMDE_FLOAT64_C(   119.68) },
      { SIMDE_FLOAT64_C(  -103.60), SIMDE_FLOAT64_C(  -123.45), SIMDE_FLOAT64_C(   877.34), SIMDE_FLOAT64_C(   691.14),
        SIMDE_FLOAT64_C(  -384.94), SIMDE_FLOAT64_C(   -94.43), SIMDE_FLOAT64_C(    97.55), SIMDE_FLOAT64_C(   628.08) } },
    { { SIMDE_FLOAT64_C(   885.92), SIMDE_FLOAT64_C(    44.83), SIMDE_FLOAT64_C(    16.24), SIMDE_FLOAT64_C(   406.73),
        SIMDE_FLOAT64_C(   594.28), SIMDE_FLOAT64_C(   115.64), SIMDE_FLOAT64_C(   -30.68), SIMDE_FLOAT64_C(    61.77) },
      { SIMDE_FLOAT64_C(   315.57), SIMDE_FLOAT64_C(   742.41), SIMDE_FLOAT64_C(  -933.83), SIMDE_FLOAT64_C(   177.22),
        SIMDE_FLOAT64_C(  -325.59), SIMDE_FLOAT64_C(  -705.62), SIMDE_FLOAT64_C(  -782.37), SIMDE_FLOAT64_C(   570.81) },
      { SIMDE_FLOAT64_C(   885.92), SIMDE_FLOAT64_C(    44.83), SIMDE_FLOAT64_C(   -16.24), SIMDE_FLOAT64_C(   406.73),
        SIMDE_FLOAT64_C(  -594.28), SIMDE_FLOAT64_C(  -115.64), SIMDE_FLOAT64_C(   -30.68), SIMDE_FLOAT64_C(    61.77) } },
    { { SIMDE_FLOAT64_C(   417.83), SIMDE_FLOAT64_C(  -659.71), SIMDE_FLOAT64_C(   879.67), SIMDE_FLOAT64_C(  -967.11),
        SIMDE_FLOAT64_C(   245.86), SIMDE_FLOAT64_C(  -217.88), SIMDE_FLOAT64_C(  -595.19), SIMDE_FLOAT64_C(   396.47) },
      { SIMDE_FLOAT64_C(   557.95), SIMDE_FLOAT64_C(   870.32), SIMDE_FLOAT64_C(    15.35), SIMDE_FLOAT64_C(  -713.75),
        SIMDE_FLOAT64_C(  -380.15), SIMDE_FLOAT64_C(  -182.49), SIMDE_FLOAT64_C(   405.93), SIMDE_FLOAT64_C(  -494.24) },
      { SIMDE_FLOAT64_C(   417.83), SIMDE_FLOAT64_C(   659.71), SIMDE_FLOAT64_C(   879.67), SIMDE_FLOAT64_C(  -967.11),
        SIMDE_FLOAT64_C(  -245.86), SIMDE_FLOAT64_C(  -217.88), SIMDE_FLOAT64_C(   595.19), SIMDE_FLOAT64_C(  -396.47) } },
    { { SIMDE_FLOAT64_C(   862.34), SIMDE_FLOAT64_C(  -577.83), SIMDE_FLOAT64_C(   912.49), SIMDE_FLOAT64_C(   456.63),
        SIMDE_FLOAT64_C(   537.81), SIMDE_FLOAT64_C(  -118.19), SIMDE_FLOAT64_C(  -481.60), SIMDE_FLOAT64_C(  -146.63) },
      { SIMDE_FLOAT64_C(  -375.77), SIMDE_FLOAT64_C(  -415.43), SIMDE_FLOAT64_C(  -969.41), SIMDE_FLOAT64_C(   298.64),
        SIMDE_FLOAT64_C(  -121.05), SIMDE_FLOAT64_C(  -751.77), SIMDE_FLOAT64_C(  -130.56), SIMDE_FLOAT64_C(  -703.22) },
      { SIMDE_FLOAT64_C(  -862.34), SIMDE_FLOAT64_C(  -577.83), SIMDE_FLOAT64_C(  -912.49), SIMDE_FLOAT64_C(   456.63),
        SIMDE_FLOAT64_C(  -537.81), SIMDE_FLOAT64_C(  -118.19), SIMDE_FLOAT64_C(  -481.60), SIMDE_FLOAT64_C(  -146.63) } },
    { { SIMDE_FLOAT64_C(  -411.48), SIMDE_FLOAT64_C(  -250.89), SIMDE_FLOAT64_C(  -670.33), SIMDE_FLOAT64_C(   834.38),
        SIMDE_FLOAT64_C(   531.22), SIMDE_FLOAT64_C(  -265.52), SIMDE_FLOAT64_C(   230.85), SIMDE_FLOAT64_C(    89.18) },
      { SIMDE_FLOAT64_C(  -395.20), SIMDE_FLOAT64_C(  -753.80), SIMDE_FLOAT64_C(   375.43), SIMDE_FLOAT64_C(   224.64),
        SIMDE_FLOAT64_C(    63.71), SIMDE_FLOAT64_C(  -218.65), SIMDE_FLOAT64_C(   730.41), SIMDE_FLOAT64_C(   -73.95) },
      { SIMDE_FLOAT64_C(  -411.48), SIMDE_FLOAT64_C(  -250.89), SIMDE_FLOAT64_C(   670.33), SIMDE_FLOAT64_C(   834.38),
        SIMDE_FLOAT64_C(   531.22), SIMDE_FLOAT64_C(  -265.52), SIMDE_FLOAT64_C(   230.85), SIMDE_FLOAT64_C(   -89.18) } },
    { { SIMDE_FLOAT64_C(   203.52), SIMDE_FLOAT64_C(   642.90), SIMDE_FLOAT64_C(  -617.32), SIMDE_FLOAT64_C(  -258.67),
        SIMDE_FLOAT64_C(  -475.29), SIMDE_FLOAT64_C(   -98.92), SIMDE_FLOAT64_C(   594.70), SIMDE_FLOAT64_C(   148.94) },
      { SIMDE_FLOAT64_C(   485.65), SIMDE_FLOAT64_C(   625.29), SIMDE_FLOAT64_C(  -552.43), SIMDE_FLOAT64_C(  -635.40),
        SIMDE_FLOAT64_C(   873.52), SIMDE_FLOAT64_C(   317.01), SIMDE_FLOAT64_C(  -338.62), SIMDE_FLOAT64_C(  -537.96) },
      { SIMDE_FLOAT64_C(   203.52), SIMDE_FLOAT64_C(   642.90), SIMDE_FLOAT64_C(  -617.32), SIMDE_FLOAT64_C(  -258.67),
        SIMDE_FLOAT64_C(   475.29), SIMDE_FLOAT64_C(    98.92), SIMDE_FLOAT64_C(  -594.70), SIMDE_FLOAT64_C(  -148.94) } },
    { { SIMDE_FLOAT64_C(  -933.88), SIMDE_FLOAT64_C(    -8.95), SIMDE_FLOAT64_C(  -703.59), SIMDE_FLOAT64_C(   597.35),
        SIMDE_FLOAT64_C(   725.52), SIMDE_FLOAT64_C(   527.26), SIMDE_FLOAT64_C(  -313.48), SIMDE_FLOAT64_C(  -669.68) },
      { SIMDE_FLOAT64_C(   773.46), SIMDE_FLOAT64_C(  -938.05), SIMDE_FLOAT64_C(   554.96), SIMDE_FLOAT64_C(  -162.83),
        SIMDE_FLOAT64_C(  -156.70), SIMDE_FLOAT64_C(   285.37), SIMDE_FLOAT64_C(   763.23), SIMDE_FLOAT64_C(  -953.18) },
      { SIMDE_FLOAT64_C(   933.88), SIMDE_FLOAT64_C(    -8.95), SIMDE_FLOAT64_C(   703.59), SIMDE_FLOAT64_C(  -597.35),
        SIMDE_FLOAT64_C(  -725.52), SIMDE_FLOAT64_C(   527.26), SIMDE_FLOAT64_C(   313.48), SIMDE_FLOAT64_C(  -669.68) } },
    { { SIMDE_FLOAT64_C(   -71.73), SIMDE_FLOAT64_C(  -854.09), SIMDE_FLOAT64_C(  -211.85), SIMDE_FLOAT64_C(   452.98),
        SIMDE_FLOAT64_C(    46.99), SIMDE_FLOAT64_C(  -617.15), SIMDE_FLOAT64_C(  -398.09), SIMDE_FLOAT64_C(  -467.35) },
      { SIMDE_FLOAT64_C(  -991.86), SIMDE_FLOAT64_C(    49.48), SIMDE_FLOAT64_C(  -102.75), SIMDE_FLOAT64_C(   881.66),
        SIMDE_FLOAT64_C(  -633.50), SIMDE_FLOAT64_C(   558.63), SIMDE_FLOAT64_C(  -656.30), SIMDE_FLOAT64_C(  -567.38) },
      { SIMDE_FLOAT64_C(   -71.73), SIMDE_FLOAT64_C(   854.09), SIMDE_FLOAT64_C(  -211.85), SIMDE_FLOAT64_C(   452.98),
        SIMDE_FLOAT64_C(   -46.99), SIMDE_FLOAT64_C(   617.15), SIMDE_FLOAT64_C(  -398.09), SIMDE_FLOAT64_C(  -467.35) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_x_mm512_copysign_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_x_mm512_copysign_pd(a, b);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_copysign_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm512_copysign_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>