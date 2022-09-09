/* Genarated C codes for benchmarks in Jun 1, 2022 */

#include "benchmarks.h"

#if defined(NOOPT)
  #pragma GCC push_options
  #pragma GCC optimize ("O0")
#endif

int64_t sum(const int64_t * aa_1,const int64_t al_2)
{
   int64_t v_3 = 0;
   int64_t i_4;
   for (i_4 = 0; i_4 <= (al_2 - 1); i_4++)
   {
      int64_t t_5;
      t_5 = aa_1[i_4];
      v_3 = v_3 + t_5;
   }
   return v_3;}

int64_t sum_squares(const int64_t * aa_6,const int64_t al_7)
{
   int64_t v_8 = 0;
   int64_t i_9;
   for (i_9 = 0; i_9 <= (al_7 - 1); i_9++)
   {
      int64_t t_10;
      int64_t t_11;
      t_10 = aa_6[i_9];
      t_11 = t_10 * t_10;
      v_8 = v_8 + t_11;
   }
   return v_8;}

int64_t maps(const int64_t * aa_12,const int64_t al_13)
{
   int64_t v_14 = 0;
   int64_t i_15;
   for (i_15 = 0; i_15 <= (al_13 - 1); i_15++)
   {
      int64_t t_16;
      int64_t t_17;
      int64_t t_18;
      int64_t t_19;
      int64_t t_20;
      int64_t t_21;
      int64_t t_22;
      int64_t t_23;
      t_16 = aa_12[i_15];
      t_17 = t_16;
      t_18 = t_17 * 2;
      t_19 = t_18 * 3;
      t_20 = t_19 * 4;
      t_21 = t_20 * 5;
      t_22 = t_21 * 6;
      t_23 = t_22 * 7;
      v_14 = v_14 + t_23;
   }
   return v_14;}

int64_t filters(const int64_t * aa_24,const int64_t al_25)
{
   int64_t v_26 = 0;
   int64_t i_27;
   for (i_27 = 0; i_27 <= (al_25 - 1); i_27++)
   {
      int64_t t_28;
      t_28 = aa_24[i_27];
      if ((t_28 > 1) && ((t_28 > 2) && ((t_28 > 3) && ((t_28 > 4) && ((t_28 >
           5) && ((t_28 > 6) && (t_28 > 7)))))))
      {
         v_26 = v_26 + t_28;
      }
   }
   return v_26;}

int64_t sum_squares_even(const int64_t * aa_29,const int64_t al_30)
{
   int64_t v_31 = 0;
   int64_t i_32;
   for (i_32 = 0; i_32 <= (al_30 - 1); i_32++)
   {
      int64_t t_33;
      t_33 = aa_29[i_32];
      if ((t_33 % 2) == 0)
      {
         int64_t t_34;
         t_34 = t_33 * t_33;
         v_31 = v_31 + t_34;
      }
   }
   return v_31;}

int64_t cart(const int64_t * a1a_35,const int64_t a1l_36,
const int64_t * a2a_37,const int64_t a2l_38)
{
   int64_t v_39 = 0;
   int64_t i_40;
   for (i_40 = 0; i_40 <= (a1l_36 - 1); i_40++)
   {
      int64_t t_41;
      int64_t i_42;
      t_41 = a1a_35[i_40];
      for (i_42 = 0; i_42 <= (a2l_38 - 1); i_42++)
      {
         int64_t t_43;
         int64_t t_44;
         t_43 = a2a_37[i_42];
         t_44 = t_41 * t_43;
         v_39 = v_39 + t_44;
      }
   }
   return v_39;}

int64_t dot_product(const int64_t * a1a_45,const int64_t a1l_46,
const int64_t * a2a_47,const int64_t a2l_48)
{
   int64_t v_49 = 0;
   int64_t i_50;
   for (i_50 = 0; i_50 <= ((a1l_46 - 1) < (a2l_48 - 1) ? a1l_46 - 1 : a2l_48
         - 1); i_50++)
   {
      int64_t t_51;
      int64_t t_52;
      t_51 = a1a_45[i_50];
      t_52 = a2a_47[i_50];
      v_49 = v_49 + (t_51 * t_52);
   }
   return v_49;}

int64_t flatmap_after_zipwith(const int64_t * a1a_53,const int64_t a1l_54,
const int64_t * a2a_55,const int64_t a2l_56)
{
   int64_t v_57 = 0;
   int64_t i_58;
   for (i_58 = 0; i_58 <= ((a1l_54 - 1) < (a1l_54 - 1) ? a1l_54 - 1 : a1l_54
         - 1); i_58++)
   {
      int64_t t_59;
      int64_t t_60;
      int64_t i_61;
      t_59 = a1a_53[i_58];
      t_60 = a1a_53[i_58];
      for (i_61 = 0; i_61 <= (a2l_56 - 1); i_61++)
      {
         int64_t t_62;
         int64_t t_63;
         t_62 = a2a_55[i_61];
         t_63 = t_62 + (t_59 + t_60);
         v_57 = v_57 + t_63;
      }
   }
   return v_57;}

int64_t zipwith_after_flatmap(const int64_t * a1a_64,const int64_t a1l_65,
const int64_t * a2a_66,const int64_t a2l_67)
{
   int64_t v_68 = 0;
   int64_t v_69 = 0;
   int64_t i_70;
   for (i_70 = 0; (i_70 <= (a1l_65 - 1)) && (v_69 <= (a1l_65 - 1)); i_70++)
   {
      int64_t t_71;
      int64_t i_72;
      t_71 = a1a_64[i_70];
      for (i_72 = 0; (i_72 <= (a2l_67 - 1)) && (v_69 <= (a1l_65 - 1));
            i_72++)
      {
         int64_t t_73;
         int64_t t_74;
         int64_t t_75;
         t_73 = a2a_66[i_72];
         t_74 = t_73 + t_71;
         t_75 = a1a_64[v_69];
         v_68 = v_68 + (t_75 + t_74);
         v_69++;
      }
   }
   return v_68;}

int64_t flat_map_take(const int64_t * a1a_76,const int64_t a1l_77,
const int64_t * a2a_78,const int64_t a2l_79)
{
   int64_t v_80 = 0;
   int64_t v_81 = 20000000;
   int64_t i_82;
   for (i_82 = 0; (i_82 <= (a1l_77 - 1)) && (v_81 > 0); i_82++)
   {
      int64_t t_83;
      int64_t i_84;
      t_83 = a1a_76[i_82];
      for (i_84 = 0; (i_84 <= (a2l_79 - 1)) && (v_81 > 0); i_84++)
      {
         int64_t t_85;
         int64_t t_86;
         t_85 = a2a_78[i_84];
         t_86 = t_83 * t_85;
         v_81--;
         v_80 = v_80 + t_86;
      }
   }
   return v_80;}

int64_t zip_filter_filter(const int64_t * a1a_87,const int64_t a1l_88,
const int64_t * a2a_89,const int64_t a2l_90)
{
   int64_t v_91 = 0;
   int64_t v_92 = 0;
   int64_t i_93;
   for (i_93 = 0; (i_93 <= (a1l_88 - 1)) && (v_92 <= (a2l_90 - 1)); i_93++)
   {
      int64_t t_94;
      t_94 = a1a_87[i_93];
      if (t_94 > 7)
      {
         bool v_95 = 1;
         do
         {
            int64_t t_96;
            t_96 = a2a_89[v_92];
            if (t_96 > 5)
            {
               v_91 = v_91 + (t_94 + t_96);
               v_95 = 0;
            }
            v_92++;
         }
         while (v_95 && (v_92 <= (a2l_90 - 1)));
      }
   }
   return v_91;}

int64_t zip_flat_flat(const int64_t * a1a_97,const int64_t a1l_98,
const int64_t * a2a_99,const int64_t a2l_100)
{
   int64_t v_103 = 0;
   int64_t v_104 = 200000000;
   int64_t v_105 = 0;
   bool v_107 = 1;
   bool v_108 = 0;
   int64_t v_109;
   int64_t v_110 = 0;
   int64_t i_111;
   for (i_111 = 0; (i_111 <= (a1l_98 - 1)) && (v_107 && (v_104 > 0));
         i_111++)
   {
      int64_t t_112;
      int64_t i_113;
      t_112 = a1a_97[i_111];
      for (i_113 = 0; (i_113 <= (a2l_100 - 1)) && (v_107 && (v_104 > 0));
            i_113++)
      {
         int64_t t_114;
         int64_t t_115;
         bool v_116 = 1;
         t_114 = a2a_99[i_113];
         t_115 = t_112 * t_114;
         while (v_116)
         {
            if (!v_108)
            {
               if (v_105 <= (a2l_100 - 1))
               {
                  int64_t t_119;
                  t_119 = a2a_99[v_105];
                  v_109 = t_119;
                  v_110 = 0;
                  v_108 = v_110 <= (a1l_98 - 1);
                  v_105++;
               }
               else {
                       v_107 = 0;
                       v_116 = 0;
               }
            }
            if (v_108)
            {
               int64_t t_117;
               int64_t t_118;
               t_117 = a1a_97[v_110];
               t_118 = v_109 - t_117;
               v_104--;
               v_103 = v_103 + (t_115 + t_118);
               v_116 = 0;
               v_110++;
               v_108 = v_110 <= (a1l_98 - 1);
            }
         }
      }
   }
   return v_103;}

int64_t decoding(const int64_t * a1a_120,const int64_t a1l_121,
const int64_t * a2a_122,const int64_t a2l_123)
{
   int64_t v_126 = 0;
   int64_t v_127 = 0;
   bool v_129 = 1;
   bool v_130 = 0;
   int64_t v_131;
   int64_t v_132 = 0;
   int64_t i_133;
   for (i_133 = 0; (i_133 <= (a1l_121 - 1)) && v_129; i_133++)
   {
      int64_t t_134;
      int64_t i_135;
      t_134 = a1a_120[i_133];
      for (i_135 = 0; (i_135 <= t_134) && v_129; i_135++)
      {
         if (i_135 < t_134)
         {
            bool v_138 = 1;
            while (v_138)
            {
               if (!v_130)
               {
                  if (v_127 <= (a2l_123 - 1))
                  {
                     int64_t t_139;
                     t_139 = a2a_122[v_127];
                     v_131 = t_139;
                     v_132 = 0;
                     v_130 = v_132 <= v_131;
                     v_127++;
                  }
                  else {
                          v_129 = 0;
                          v_138 = 0;
                  }
               }
               if (v_130)
               {
                  if (v_132 < v_131)
                  {
                     v_126 = v_126;
                     v_138 = 0;
                  }
                  else {
                          if (v_132 < 255)
                          {
                             v_126 = v_126 + 1;
                             v_138 = 0;
                          }
                  }
                  v_132++;
                  v_130 = v_132 <= v_131;
               }
            }
         }
         else {
                 if (i_135 < 255)
                 {
                    bool v_136 = 1;
                    while (v_136)
                    {
                       if (!v_130)
                       {
                          if (v_127 <= (a2l_123 - 1))
                          {
                             int64_t t_137;
                             t_137 = a2a_122[v_127];
                             v_131 = t_137;
                             v_132 = 0;
                             v_130 = v_132 <= v_131;
                             v_127++;
                          }
                          else {
                                  v_129 = 0;
                                  v_136 = 0;
                          }
                       }
                       if (v_130)
                       {
                          if (v_132 < v_131)
                          {
                             v_126 = v_126 + 1;
                             v_136 = 0;
                          }
                          else {
                                  if (v_132 < 255)
                                  {
                                     v_126 = v_126 + 1;
                                     v_136 = 0;
                                  }
                          }
                          v_132++;
                          v_130 = v_132 <= v_131;
                       }
                    }
                 }
         }
      }
   }
   return v_126;}

#if defined(NOOPT)
  #pragma GCC pop_options
#endif
