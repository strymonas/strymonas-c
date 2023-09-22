/* Genarated C codes for benchmarks in Sep 13, 2023 */

#include "benchmarks.h"

#if defined(NOOPT)
  #pragma GCC push_options
  #pragma GCC optimize ("O0")
#endif

int64_t sum(int64_t const n_139,int64_t * const a_140){
  int64_t x_141 = 0;
  for (int64_t i_142 = 0; i_142 < n_139; i_142 += 1){
    int64_t const t_143 = a_140[i_142];
    x_141 = x_141 + t_143;
  }
  return x_141;
}


int64_t sum_squares(int64_t const n_144,int64_t * const a_145){
  int64_t x_146 = 0;
  for (int64_t i_147 = 0; i_147 < n_144; i_147 += 1){
    int64_t const t_148 = a_145[i_147];
    int64_t const t_149 = t_148 * t_148;
    x_146 = x_146 + t_149;
  }
  return x_146;
}


int64_t maps(int64_t const n_150,int64_t * const a_151){
  int64_t x_152 = 0;
  for (int64_t i_153 = 0; i_153 < n_150; i_153 += 1){
    int64_t const t_154 = a_151[i_153];
    int64_t const t_155 = t_154 * 2;
    int64_t const t_156 = t_155 * 3;
    int64_t const t_157 = t_156 * 4;
    int64_t const t_158 = t_157 * 5;
    int64_t const t_159 = t_158 * 6;
    int64_t const t_160 = t_159 * 7;
    x_152 = x_152 + t_160;
  }
  return x_152;
}


int64_t filters(int64_t const n_161,int64_t * const a_162){
  int64_t x_163 = 0;
  for (int64_t i_164 = 0; i_164 < n_161; i_164 += 1){
    int64_t const t_165 = a_162[i_164];
    if ((t_165 > 1)
        && ((t_165 > 2)
            && ((t_165 > 3)
                && ((t_165 > 4)
                    && ((t_165 > 5) && ((t_165 > 6) && (t_165 > 7)))))))
    
      x_163 = x_163 + t_165;
  }
  return x_163;
}


int64_t sum_squares_even(int64_t const n_166,int64_t * const a_167){
  int64_t x_168 = 0;
  for (int64_t i_169 = 0; i_169 < n_166; i_169 += 1){
    int64_t const t_170 = a_167[i_169];
    if ((t_170 % 2) == 0)
    {
      int64_t const t_171 = t_170 * t_170;
      x_168 = x_168 + t_171;
    }
  }
  return x_168;
}


int64_t cart(int64_t const n_172,int64_t * const a_173,int64_t const n_174,
            int64_t * const a_175){
  int64_t x_176 = 0;
  for (int64_t i_177 = 0; i_177 < n_172; i_177 += 1){
    int64_t const t_178 = a_173[i_177];
    for (int64_t i_179 = 0; i_179 < n_174; i_179 += 1){
      int64_t const t_180 = a_175[i_179];
      int64_t const t_181 = t_178 * t_180;
      x_176 = x_176 + t_181;
    }
  }
  return x_176;
}


int64_t dot_product(int64_t const n_182,int64_t * const a_183,
                   int64_t const n_184,int64_t * const a_185){
  int64_t x_186 = 0;
  for (int64_t i_187 = 0; i_187 < (n_182 < n_184 ? n_182 : n_184);
        i_187 += 1){
    int64_t const t_188 = a_183[i_187];
    int64_t const t_189 = a_185[i_187];
    x_186 = x_186 + (t_188 * t_189);
  }
  return x_186;
}


int64_t flatmap_after_zipwith(int64_t const n_190,int64_t * const a_191,
                             int64_t const n_192,int64_t * const a_193){
  int64_t x_194 = 0;
  for (int64_t i_195 = 0; i_195 < (n_190 < n_190 ? n_190 : n_190);
        i_195 += 1){
    int64_t const t_196 = a_191[i_195];
    int64_t const t_197 = a_191[i_195];
    for (int64_t i_198 = 0; i_198 < n_192; i_198 += 1){
      int64_t const t_199 = a_193[i_198];
      int64_t const t_200 = t_199 + (t_196 + t_197);
      x_194 = x_194 + t_200;
    }
  }
  return x_194;
}


int64_t zipwith_after_flatmap(int64_t const n_201,int64_t * const a_202,
                             int64_t const n_203,int64_t * const a_204){
  int64_t x_205 = 0;
  int64_t x_206 = 0;
  for (int64_t i_207 = 0; (i_207 < n_201) && (x_206 < n_201); i_207 += 1){
    int64_t const t_208 = a_202[i_207];
    for (int64_t i_209 = 0; (i_209 < n_203) && (x_206 < n_201); i_209 += 1){
      int64_t const t_210 = a_204[i_209];
      int64_t const t_211 = t_210 + t_208;
      int64_t const t_212 = a_202[x_206];
      x_205 = x_205 + (t_212 + t_211);
      x_206++;
    }
  }
  return x_205;
}


int64_t flat_map_take(int64_t const n_213,int64_t * const a_214,
                     int64_t const n_215,int64_t * const a_216){
  int64_t x_217 = 0;
  int64_t x_218 = 20000000;
  for (int64_t i_219 = 0; (i_219 < n_213) && (x_218 > 0); i_219 += 1){
    int64_t const t_220 = a_214[i_219];
    for (int64_t i_221 = 0; (i_221 < n_215) && (x_218 > 0); i_221 += 1){
      int64_t const t_222 = a_216[i_221];
      int64_t const t_223 = t_220 * t_222;
      x_218--;
      x_217 = x_217 + t_223;
    }
  }
  return x_217;
}


int64_t zip_filter_filter(int64_t const n_224,int64_t * const a_225,
                         int64_t const n_226,int64_t * const a_227){
  int64_t x_228 = 0;
  int64_t x_229 = 0;
  for (int64_t i_230 = 0; (i_230 < n_224) && (x_229 < n_226); i_230 += 1){
    int64_t const t_231 = a_225[i_230];
    if (t_231 > 7)
    {
      bool x_232 = true;
      while (x_232 && (x_229 < n_226))
      {
        int64_t const t_233 = a_227[x_229];
        if (t_233 > 5)
        {
          x_228 = x_228 + (t_231 + t_233);
          x_232 = false;
        }
        x_229++;
      }
    }
  }
  return x_228;
}


int64_t zip_flat_flat(int64_t const n_234,int64_t * const a_235,
                     int64_t const n_236,int64_t * const a_237){
  int64_t x_240 = 0;
  int64_t x_241 = 200000000;
  int64_t x_242 = 0;
  bool x_244 = true;
  bool x_245 = false;
  int64_t x_246 = 0;
  int64_t x_247 = 0;
  for (int64_t i_248 = 0; (i_248 < n_234) && (x_244 && (x_241 > 0));
        i_248 += 1){
    int64_t const t_249 = a_235[i_248];
    for (int64_t i_250 = 0; (i_250 < n_236) && (x_244 && (x_241 > 0));
          i_250 += 1){
      int64_t const t_251 = a_237[i_250];
      int64_t const t_252 = t_249 * t_251;
      bool x_253 = true;
      while (x_253)
      {
        if (!x_245)
        {if (x_242 < n_236)
           {
             int64_t const t_256 = a_237[x_242];
             x_246 = t_256;
             x_247 = 0;
             x_245 = x_247 < n_234;
             x_242++;
           }
           else {
             x_244 = false;
             x_253 = false;
           }}
        if (x_245)
        {
          int64_t const t_254 = a_235[x_247];
          int64_t const t_255 = x_246 - t_254;
          x_241--;
          x_240 = x_240 + (t_252 + t_255);
          x_253 = false;
          x_247++;
          x_245 = x_247 < n_234;
        }
      }
    }
  }
  return x_240;
}


int64_t decoding(int64_t const n_257,int64_t * const a_258,
                int64_t const n_259,int64_t * const a_260){
  int64_t x_263 = 0;
  int64_t x_264 = 0;
  bool x_266 = true;
  bool x_267 = false;
  int64_t x_268 = 0;
  int64_t x_269 = 0;
  for (int64_t i_270 = 0; (i_270 < n_257) && x_266; i_270 += 1){
    int64_t const t_271 = a_258[i_270];
    for (int64_t i_272 = 0; (i_272 < (t_271 + 1)) && x_266; i_272 += 1){
    if (i_272 < t_271)
      {
        bool x_275 = true;
        while (x_275)
        {
          if (!x_267)
          {if (x_264 < n_259)
             {
               int64_t const t_276 = a_260[x_264];
               x_268 = t_276;
               x_269 = 0;
               x_267 = x_269 < (x_268 + 1);
               x_264++;
             }
             else {
               x_266 = false;
               x_275 = false;
             }}
          if (x_267)
          {
            if (x_269 < x_268)
            {
              x_263 = x_263;
              x_275 = false;
            }
            else {if (x_269 < 255)
                    {
                      x_263 = x_263 + 1;
                      x_275 = false;
                    }}
            x_269++;
            x_267 = x_269 < (x_268 + 1);
          }
        }
      }
      else {if (i_272 < 255)
              {
                bool x_273 = true;
                while (x_273)
                {
                  if (!x_267)
                  {if (x_264 < n_259)
                     {
                       int64_t const t_274 = a_260[x_264];
                       x_268 = t_274;
                       x_269 = 0;
                       x_267 = x_269 < (x_268 + 1);
                       x_264++;
                     }
                     else {
                       x_266 = false;
                       x_273 = false;
                     }}
                  if (x_267)
                  {
                    if (x_269 < x_268)
                    {
                      x_263 = x_263 + 1;
                      x_273 = false;
                    }
                    else {if (x_269 < 255)
                            {
                              x_263 = x_263 + 1;
                              x_273 = false;
                            }}
                    x_269++;
                    x_267 = x_269 < (x_268 + 1);
                  }
                }
              }}}
  }
  return x_263;
}

#if defined(NOOPT)
  #pragma GCC pop_options
#endif
