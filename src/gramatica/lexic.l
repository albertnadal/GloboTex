%name MyScanner
%define MEMBERS public: int num_linia; int car;

%{
// Escàner lèxic
void sum(int& car, int& yyleng) {car=car+yyleng;}
%}

%x comentari matematic macro_desconeguda entorn_macro_desconeguda
%%

"%"                             {BEGIN(comentari);}
<comentari>[^\n]*               /* descarta qualsevol caràcter excepte un canvi de linia */
<comentari>\n                   {num_linia++; car=0; BEGIN(INITIAL);}

"$$"                            {sum(car,yyleng);BEGIN(matematic);}
"$"                             {sum(car,yyleng);BEGIN(matematic);}
"\\("                           {sum(car,yyleng);BEGIN(matematic);}
"\\begin{align}"                {sum(car,yyleng);BEGIN(matematic);}
"\\begin{math}"                 {sum(car,yyleng);BEGIN(matematic);}
<matematic>[^$\n]*              {sum(car,yyleng); return AnalitzadorSintactic::MATEMATIC;}
<matematic>"\n"                 {num_linia++; car=0;}
<matematic>"$$"                 {sum(car,yyleng);BEGIN(INITIAL);}
<matematic>"$"                  {sum(car,yyleng);BEGIN(INITIAL);}
<matematic>"\\)"                {sum(car,yyleng);BEGIN(INITIAL);}
<matematic>"\\end{math}"        {sum(car,yyleng);BEGIN(INITIAL);}
<matematic>"\\end{align}"       {sum(car,yyleng);BEGIN(INITIAL);}

[^\\\n{}\[\]%$,]*               {sum(car,yyleng); return AnalitzadorSintactic::TEXT_CONTINGUT;}
","                             {sum(car,yyleng); return AnalitzadorSintactic::COMA;}
"["                             {sum(car,yyleng); return AnalitzadorSintactic::CO;}
"]"                             {sum(car,yyleng); return AnalitzadorSintactic::CT;}
"{"                             {sum(car,yyleng); return AnalitzadorSintactic::PO;}
"}"                             {sum(car,yyleng); return AnalitzadorSintactic::PT;}
\\\\                            {sum(car,yyleng); return AnalitzadorSintactic::FP;}
"\\par"                         {sum(car,yyleng); return AnalitzadorSintactic::FP;}
"\\linebreak"                   {sum(car,yyleng); return AnalitzadorSintactic::NL;}
"\\newline"                     {sum(car,yyleng); return AnalitzadorSintactic::NL;}
"\\rule"                        {sum(car,yyleng); return AnalitzadorSintactic::LINIA;}
"\\includegraphics"             {sum(car,yyleng); return AnalitzadorSintactic::IMATGE;}
"\\epsfig"                      {sum(car,yyleng); return AnalitzadorSintactic::IMATGEFIG;}
"\\hline"                       {sum(car,yyleng); return AnalitzadorSintactic::HLINE;}
"\\>"                           {sum(car,yyleng); return AnalitzadorSintactic::TAB;}
"\\="                           {sum(car,yyleng); return AnalitzadorSintactic::POS_TAB;}
"\n"                            {num_linia++; car=0;}

"\\`{a}"|"\\grave{a}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_OBERT;}
"\\'{a}"|"\\acute{a}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_TANCAT;}
"\\^{a}"|"\\hat{a}"             {sum(car,yyleng); return AnalitzadorSintactic::A_A_CIRCUM;}
"\\\"{a}"|"\\ddot{a}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_DIERESIS;}
"\\~{a}"|"\\tilde{a}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_TILDE;}
"\\={a}"|"\\bar{a}"             {sum(car,yyleng); return AnalitzadorSintactic::A_A_MACRON;}
"\\.{a}"|"\\dot{a}"             {sum(car,yyleng); return AnalitzadorSintactic::A_A_DOT;}
"\\u{a}"|"\\breve{a}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_BREVE;}
"\\v{a}"|"\\check{a}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_CHECK;}
"\\H{a}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_HUNGARIAN;}
"\\t{aa}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_A_TIE;}
"\\c{a}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_CEDILLA;}
"\\d{a}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_DOTUNDER;}
"\\b{a}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_BARUNDER;}
"\\vec{a}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_A_VECTOR;}
"\\r{a}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_RING;}
"\\ae"                          {sum(car,yyleng); return AnalitzadorSintactic::A_A_AE_DIFTONG;}

"\\`{A}"|"\\grave{A}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_OBERT_M;}
"\\'{A}"|"\\acute{A}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_TANCAT_M;}
"\\^{A}"|"\\hat{A}"             {sum(car,yyleng); return AnalitzadorSintactic::A_A_CIRCUM_M;}
"\\\"{A}"|"\\ddot{A}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_DIERESIS_M;}
"\\~{A}"|"\\tilde{A}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_TILDE_M;}
"\\={A}"|"\\bar{A}"             {sum(car,yyleng); return AnalitzadorSintactic::A_A_MACRON_M;}
"\\.{A}"|"\\dot{A}"             {sum(car,yyleng); return AnalitzadorSintactic::A_A_DOT_M;}
"\\u{A}"|"\\breve{A}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_BREVE_M;}
"\\v{A}"|"\\check{A}"           {sum(car,yyleng); return AnalitzadorSintactic::A_A_CHECK_M;}
"\\H{A}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_HUNGARIAN_M;}
"\\t{AA}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_A_TIE_M;}
"\\c{A}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_CEDILLA_M;}
"\\d{A}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_DOTUNDER_M;}
"\\b{A}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_BARUNDER_M;}
"\\r{A}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_A_RING_M;}
"\\AE"                          {sum(car,yyleng); return AnalitzadorSintactic::A_A_AE_DIFTONG_M;}

"\\`{e}"|"\\grave{e}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_OBERT;}
"\\'{e}"|"\\acute{e}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_TANCAT;}
"\\^{e}"|"\\hat{e}"             {sum(car,yyleng); return AnalitzadorSintactic::A_E_CIRCUM;}
"\\\"{e}"|"\\ddot{e}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_DIERESIS;}
"\\~{e}"|"\\tilde{e}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_TILDE;}
"\\={e}"|"\\bar{e}"             {sum(car,yyleng); return AnalitzadorSintactic::A_E_MACRON;}
"\\.{e}"|"\\dot{e}"             {sum(car,yyleng); return AnalitzadorSintactic::A_E_DOT;}
"\\u{e}"|"\\breve{e}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_BREVE;}
"\\v{e}"|"\\check{e}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_CHECK;}
"\\H{e}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_HUNGARIAN;}
"\\t{ee}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_E_TIE;}
"\\c{e}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_CEDILLA;}
"\\d{e}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_DOTUNDER;}
"\\b{e}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_BARUNDER;}
"\\vec{e}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_E_VECTOR;}

"\\`{E}"|"\\grave{E}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_OBERT_M;}
"\\'{E}"|"\\acute{E}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_TANCAT_M;}
"\\^{E}"|"\\hat{E}"             {sum(car,yyleng); return AnalitzadorSintactic::A_E_CIRCUM_M;}
"\\\"{E}"|"\\ddot{E}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_DIERESIS_M;}
"\\~{E}"|"\\tilde{E}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_TILDE_M;}
"\\={E}"|"\\bar{E}"             {sum(car,yyleng); return AnalitzadorSintactic::A_E_MACRON_M;}
"\\.{E}"|"\\dot{E}"             {sum(car,yyleng); return AnalitzadorSintactic::A_E_DOT_M;}
"\\u{E}"|"\\breve{E}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_BREVE_M;}
"\\v{E}"|"\\check{E}"           {sum(car,yyleng); return AnalitzadorSintactic::A_E_CHECK_M;}
"\\H{E}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_HUNGARIAN_M;}
"\\t{EE}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_E_TIE_M;}
"\\c{E}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_CEDILLA_M;}
"\\d{E}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_DOTUNDER_M;}
"\\b{E}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_E_BARUNDER_M;}

"\\`{\\i}"|"\\grave{\\i}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_OBERT;}
"\\'{\\i}"|"\\acute{\\i}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_TANCAT;}
"\\^{\\i}"|"\\hat{\\i}"         {sum(car,yyleng); return AnalitzadorSintactic::A_I_CIRCUM;}
"\\\"{\\i}"|"\\ddot{\\i}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_DIERESIS;}
"\\~{\\i}"|"\\tilde{\\i}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_TILDE;}
"\\={\\i}"|"\\bar{\\i}"         {sum(car,yyleng); return AnalitzadorSintactic::A_I_MACRON;}
"\\.{\\i}"|"\\dot{\\i}"         {sum(car,yyleng); return AnalitzadorSintactic::A_I_DOT;}
"\\u{\\i}"|"\\breve{\\i}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_BREVE;}
"\\v{\\i}"|"\\check{\\i}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_CHECK;}
"\\H{\\i}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_HUNGARIAN;}
"\\t{ii}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_I_TIE;}
"\\c{\\i}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_CEDILLA;}
"\\d{\\i}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_DOTUNDER;}
"\\b{\\i}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_BARUNDER;}
"\\vec{\\i}"                    {sum(car,yyleng); return AnalitzadorSintactic::A_I_VECTOR;}

"\\`{\\I}"|"\\grave{\\I}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_OBERT_M;}
"\\'{\\I}"|"\\acute{\\I}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_TANCAT_M;}
"\\^{\\I}"|"\\hat{\\I}"         {sum(car,yyleng); return AnalitzadorSintactic::A_I_CIRCUM_M;}
"\\\"{\\I}"|"\\ddot{\\I}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_DIERESIS_M;}
"\\~{\\I}"|"\\tilde{\\I}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_TILDE_M;}
"\\={\\I}"|"\\bar{\\I}"         {sum(car,yyleng); return AnalitzadorSintactic::A_I_MACRON_M;}
"\\.{\\I}"|"\\dot{\\I}"         {sum(car,yyleng); return AnalitzadorSintactic::A_I_DOT_M;}
"\\u{\\I}"|"\\breve{\\I}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_BREVE_M;}
"\\v{\\I}"|"\\check{\\I}"       {sum(car,yyleng); return AnalitzadorSintactic::A_I_CHECK_M;}
"\\H{\\I}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_HUNGARIAN_M;}
"\\t{II}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_I_TIE_M;}
"\\c{\\I}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_CEDILLA_M;}
"\\d{\\I}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_DOTUNDER_M;}
"\\b{\\I}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_I_BARUNDER_M;}

"\\`{o}"|"\\grave{o}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_OBERT;}
"\\'{o}"|"\\acute{o}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_TANCAT;}
"\\^{o}"|"\\hat{o}"             {sum(car,yyleng); return AnalitzadorSintactic::A_O_CIRCUM;}
"\\\"{o}"|"\\ddot{o}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_DIERESIS;}
"\\~{o}"|"\\tilde{o}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_TILDE;}
"\\={o}"|"\\bar{o}"             {sum(car,yyleng); return AnalitzadorSintactic::A_O_MACRON;}
"\\.{o}"|"\\dot{o}"             {sum(car,yyleng); return AnalitzadorSintactic::A_O_DOT;}
"\\u{o}"|"\\breve{o}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_BREVE;}
"\\v{o}"|"\\check{o}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_CHECK;}
"\\H{o}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_HUNGARIAN;}
"\\t{oo}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_O_TIE;}
"\\c{o}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_CEDILLA;}
"\\d{o}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_DOTUNDER;}
"\\b{o}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_BARUNDER;}
"\\vec{o}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_O_VECTOR;}

"\\`{O}"|"\\grave{O}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_OBERT_M;}
"\\'{O}"|"\\acute{O}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_TANCAT_M;}
"\\^{O}"|"\\hat{O}"             {sum(car,yyleng); return AnalitzadorSintactic::A_O_CIRCUM_M;}
"\\\"{O}"|"\\ddot{O}"            {sum(car,yyleng); return AnalitzadorSintactic::A_O_DIERESIS_M;}
"\\~{O}"|"\\tilde{O}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_TILDE_M;}
"\\={O}"|"\\bar{O}"             {sum(car,yyleng); return AnalitzadorSintactic::A_O_MACRON_M;}
"\\.{O}"|"\\dot{O}"             {sum(car,yyleng); return AnalitzadorSintactic::A_O_DOT_M;}
"\\u{O}"|"\\breve{O}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_BREVE_M;}
"\\v{O}"|"\\check{O}"           {sum(car,yyleng); return AnalitzadorSintactic::A_O_CHECK_M;}
"\\H{O}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_HUNGARIAN_M;}
"\\t{OO}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_O_TIE_M;}
"\\c{O}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_CEDILLA_M;}
"\\d{O}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_DOTUNDER_M;}
"\\b{O}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_O_BARUNDER_M;}

"\\`{u}"|"\\grave{u}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_OBERT;}
"\\'{u}"|"\\acute{u}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_TANCAT;}
"\\^{u}"|"\\hat{u}"             {sum(car,yyleng); return AnalitzadorSintactic::A_U_CIRCUM;}
"\\\"{u}"|"\\ddot{u}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_DIERESIS;}
"\\~{u}"|"\\tilde{u}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_TILDE;}
"\\={u}"|"\\bar{u}"             {sum(car,yyleng); return AnalitzadorSintactic::A_U_MACRON;}
"\\.{u}"|"\\dot{u}"             {sum(car,yyleng); return AnalitzadorSintactic::A_U_DOT;}
"\\u{u}"|"\\breve{u}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_BREVE;}
"\\v{u}"|"\\check{u}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_CHECK;}
"\\H{u}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_HUNGARIAN;}
"\\t{uu}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_U_TIE;}
"\\c{u}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_CEDILLA;}
"\\d{u}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_DOTUNDER;}
"\\b{u}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_BARUNDER;}
"\\vec{u}"                      {sum(car,yyleng); return AnalitzadorSintactic::A_U_VECTOR;}

"\\`{U}"|"\\grave{U}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_OBERT_M;}
"\\'{U}"|"\\acute{U}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_TANCAT_M;}
"\\^{U}"|"\\hat{U}"             {sum(car,yyleng); return AnalitzadorSintactic::A_U_CIRCUM_M;}
"\\\"{U}"|"\\ddot{U}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_DIERESIS_M;}
"\\~{U}"|"\\tilde{U}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_TILDE_M;}
"\\={U}"|"\\bar{U}"             {sum(car,yyleng); return AnalitzadorSintactic::A_U_MACRON_M;}
"\\.{U}"|"\\dot{U}"             {sum(car,yyleng); return AnalitzadorSintactic::A_U_DOT_M;}
"\\u{U}"|"\\breve{U}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_BREVE_M;}
"\\v{U}"|"\\check{U}"           {sum(car,yyleng); return AnalitzadorSintactic::A_U_CHECK_M;}
"\\H{U}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_HUNGARIAN_M;}
"\\t{UU}"                       {sum(car,yyleng); return AnalitzadorSintactic::A_U_TIE_M;}
"\\c{U}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_CEDILLA_M;}
"\\d{U}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_DOTUNDER_M;}
"\\b{U}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_U_BARUNDER_M;}

"\\c{c}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_C_TRENCADA;}
"\\c{C}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_C_TRENCADA_M;}
"\\~{n}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_N_CEDILLA;}
"\\~{N}"                        {sum(car,yyleng); return AnalitzadorSintactic::A_N_CEDILLA_M;}

"\\documentclass"               {sum(car,yyleng); return AnalitzadorSintactic::M_DOC_CLASS;}
"\\usepackage"                  {sum(car,yyleng); return AnalitzadorSintactic::M_PACKAGE;}
"\\part"                        {sum(car,yyleng); return AnalitzadorSintactic::M_PART;}
"\\section"                     {sum(car,yyleng); return AnalitzadorSintactic::M_SECCIO;}
"\\subsection"                  {sum(car,yyleng); return AnalitzadorSintactic::M_SUBSECCIO;}
"\\subsubsection"               {sum(car,yyleng); return AnalitzadorSintactic::M_SUBSUBSECCIO;}
"\\chapter"                     {sum(car,yyleng); return AnalitzadorSintactic::M_CAPITOL;}
"\\item"                        {sum(car,yyleng); return AnalitzadorSintactic::M_ITEM;}
"\\subitem"                     {sum(car,yyleng); return AnalitzadorSintactic::M_SUBITEM;}
"\\footnote"                    {sum(car,yyleng); return AnalitzadorSintactic::M_PEU_DE_PAGINA;}
"\\tableofcontents"             {sum(car,yyleng); return AnalitzadorSintactic::M_TAULA_DE_CONTINGUTS;}
"\\listoffigures"               {sum(car,yyleng); return AnalitzadorSintactic::M_LLISTA_DE_FIGURES;}
"\\listoftables"                {sum(car,yyleng); return AnalitzadorSintactic::M_LLISTA_DE_TAULES;}
"\\href"                        {sum(car,yyleng); return AnalitzadorSintactic::M_HREF;}
"\\hyperlink"                   {sum(car,yyleng); return AnalitzadorSintactic::M_LINK;}
"\\hypertarget"                 {sum(car,yyleng); return AnalitzadorSintactic::M_TARGET;}
"\\label"                       {sum(car,yyleng); return AnalitzadorSintactic::M_ETIQUETA;}
"\\ref"                         {sum(car,yyleng); return AnalitzadorSintactic::M_REFERENCIA;}
"\\paragraph"                   {sum(car,yyleng); return AnalitzadorSintactic::M_PARAGRAF;}
"\\subparagraph"                {sum(car,yyleng); return AnalitzadorSintactic::M_SUBPARAGRAF;}
"\\appendix"                    {sum(car,yyleng); return AnalitzadorSintactic::M_APENDIX;}
"\\caption"                     {sum(car,yyleng); return AnalitzadorSintactic::M_CAPTION;}
"\\cite"                        {sum(car,yyleng); return AnalitzadorSintactic::M_CITACIO;}
"\\bibitem"                     {sum(car,yyleng); return AnalitzadorSintactic::M_ITEM_BIBLIOGRAFIC;}
"\\title"                       {sum(car,yyleng); return AnalitzadorSintactic::M_TITOL;}
"\\author"                      {sum(car,yyleng); return AnalitzadorSintactic::M_AUTOR;}
"\\and"                         {sum(car,yyleng); return AnalitzadorSintactic::M_AND;}
"\\date"                        {sum(car,yyleng); return AnalitzadorSintactic::M_DATA;}
"\\thanks"                      {sum(car,yyleng); return AnalitzadorSintactic::M_THANKS;}
"\\maketitle"                   {sum(car,yyleng); return AnalitzadorSintactic::M_FER_TITOL;}

"\\it"                          {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_IT;}
"\\bf"                          {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_BF;}
"\\tt"                          {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_TT;}
"\\em"                          {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_EM;}
"\\emph"                        {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_EMF;}
"\\textnormal"                  {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_NORMAL;}
"\\textit"                      {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_ITALICA;}
"\\textbf"                      {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_BOLD;}
"\\underline"                   {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_SUBR;}
"\\textsuperscript"             {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_SUP;}
"\\texttt"                      {sum(car,yyleng); return AnalitzadorSintactic::M_TEXT_MECANOGRAFIC;}

"\\tiny"                        {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_TINY;}
"\\scriptsize"                  {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_SCRIPTSIZE;}
"\\footnotesize"                {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_FOOTNOTESIZE;}
"\\small"                       {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_SMALL;}
"\\normalsize"                  {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_NORMALSIZE;}
"\\large"                       {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_LARGE;}
"\\Large"                       {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_LLARGE;}
"\\LARGE"                       {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_LLLARGE;}
"\\huge"                        {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_HUGE;}
"\\Huge"                        {sum(car,yyleng); return AnalitzadorSintactic::D_TEXT_HHUGE;}

"\\$"                           {sum(car,yyleng); return AnalitzadorSintactic::S_DOLLAR; }
"\\textdollar"                  {sum(car,yyleng); return AnalitzadorSintactic::S_DOLLAR; }
"\\&"                           {sum(car,yyleng); return AnalitzadorSintactic::S_AMPERSAND; }
"\\%"                           {sum(car,yyleng); return AnalitzadorSintactic::S_TANPERCENT; }
"\\_"                           {sum(car,yyleng); return AnalitzadorSintactic::S_GUIOINF; }
"\\textunderscore"              {sum(car,yyleng); return AnalitzadorSintactic::S_GUIOINF; }
"\\{"                           {sum(car,yyleng); return AnalitzadorSintactic::S_CLAUOBERTA; }
"\\textbraceleft"               {sum(car,yyleng); return AnalitzadorSintactic::S_CLAUOBERTA; }
"\\}"                           {sum(car,yyleng); return AnalitzadorSintactic::S_CLAUTANCADA; }
"\\textbraceright"              {sum(car,yyleng); return AnalitzadorSintactic::S_CLAUTANCADA; }
"\\textless"                    {sum(car,yyleng); return AnalitzadorSintactic::S_MENORQUE; }
"\\textgreater"                 {sum(car,yyleng); return AnalitzadorSintactic::S_MAJORQUE; }
"\\neq"                         {sum(car,yyleng); return AnalitzadorSintactic::S_DIFERENT; }
"\\leq"                         {sum(car,yyleng); return AnalitzadorSintactic::S_MENOR_IGUAL; }
"\\geq"                         {sum(car,yyleng); return AnalitzadorSintactic::S_MAJOR_IGUAL; }
"\\approx"                      {sum(car,yyleng); return AnalitzadorSintactic::S_APROXIMAT; }
"\\equiv"                       {sum(car,yyleng); return AnalitzadorSintactic::S_IDENTIC; }
"\\infty"                       {sum(car,yyleng); return AnalitzadorSintactic::S_INFINIT; }
"\\cap"                         {sum(car,yyleng); return AnalitzadorSintactic::S_INTERSECCIO; }
"\\int"                         {sum(car,yyleng); return AnalitzadorSintactic::S_INTEGRAL; }
"\\surd"                        {sum(car,yyleng); return AnalitzadorSintactic::S_ARREL_QUADRADA; }
"\\sum"                         {sum(car,yyleng); return AnalitzadorSintactic::S_SUMATORI; }
"\\prod"                        {sum(car,yyleng); return AnalitzadorSintactic::S_PRODUCTORI; }
"\\triangle"                    {sum(car,yyleng); return AnalitzadorSintactic::S_INCREMENT; }
"\\partial"                     {sum(car,yyleng); return AnalitzadorSintactic::S_DIFERENCIAL; }
"\\textbackslash"               {sum(car,yyleng); return AnalitzadorSintactic::S_CONTRABARRA; }
"\\textbar"                     {sum(car,yyleng); return AnalitzadorSintactic::S_BARRA; }
"\\textbullet"                  {sum(car,yyleng); return AnalitzadorSintactic::S_PUNT; }
"\\textdaggerdbl"               {sum(car,yyleng); return AnalitzadorSintactic::S_DOBLECREUETA; }
"\\textdagger"                  {sum(car,yyleng); return AnalitzadorSintactic::S_CREUETA; }
"\\textparagraph"               {sum(car,yyleng); return AnalitzadorSintactic::S_PARAGRAF; }
"\\textsection"                 {sum(car,yyleng); return AnalitzadorSintactic::S_SECCIO; }
"\\textcopyright"               {sum(car,yyleng); return AnalitzadorSintactic::S_COPYRIGHT; }
"\\textasciicircum"             {sum(car,yyleng); return AnalitzadorSintactic::S_CIRCUM; }
"\\textasciitilde"              {sum(car,yyleng); return AnalitzadorSintactic::S_TILDE; }
"\\textregistered"              {sum(car,yyleng); return AnalitzadorSintactic::S_REGISTRAT; }
"\\texttrademark"               {sum(car,yyleng); return AnalitzadorSintactic::S_TRADEMARK; }
"\\textordfeminine"             {sum(car,yyleng); return AnalitzadorSintactic::S_AFEM; }
"\\textordmasculine"            {sum(car,yyleng); return AnalitzadorSintactic::S_OMASC; }
"\\ss"                          {sum(car,yyleng); return AnalitzadorSintactic::S_SHARP; }

"\\begin{document}"             {sum(car,yyleng); return AnalitzadorSintactic::INICI_DOC;}
"\\end{document}"               {sum(car,yyleng); return AnalitzadorSintactic::FI_DOC;}
"\\begin{abstract}"             {sum(car,yyleng); return AnalitzadorSintactic::INICI_ABSTRACT;}
"\\end{abstract}"               {sum(car,yyleng); return AnalitzadorSintactic::FI_ABSTRACT;}
"\\begin{titlepage}"            {sum(car,yyleng); return AnalitzadorSintactic::INICI_TITOL;}
"\\end{titlepage}"              {sum(car,yyleng); return AnalitzadorSintactic::FI_TITOL;}
"\\begin{enumerate}"            {sum(car,yyleng); return AnalitzadorSintactic::INICI_ENUMERAT;}
"\\end{enumerate}"              {sum(car,yyleng); return AnalitzadorSintactic::FI_ENUMERAT;}
"\\begin{figure}"               {sum(car,yyleng); return AnalitzadorSintactic::INICI_FIGURA;}
"\\end{figure}"                 {sum(car,yyleng); return AnalitzadorSintactic::FI_FIGURA;}
"\\begin{table}"                {sum(car,yyleng); return AnalitzadorSintactic::INICI_TAULA;}
"\\end{table}"                  {sum(car,yyleng); return AnalitzadorSintactic::FI_TAULA;}
"\\begin{tabular}"              {sum(car,yyleng); return AnalitzadorSintactic::INICI_TABULAR;}
"\\end{tabular}"                {sum(car,yyleng); return AnalitzadorSintactic::FI_TABULAR;}
"\\begin{equation}"             {sum(car,yyleng); return AnalitzadorSintactic::INICI_EQUACIO;}
"\\end{equation}"               {sum(car,yyleng); return AnalitzadorSintactic::FI_EQUACIO;}
"\\begin{itemize}"              {sum(car,yyleng); return AnalitzadorSintactic::INICI_ITEMIZE;}
"\\end{itemize}"                {sum(car,yyleng); return AnalitzadorSintactic::FI_ITEMIZE;}
"\\begin{description}"              {sum(car,yyleng); return AnalitzadorSintactic::INICI_ITEMIZE;}
"\\end{description}"                {sum(car,yyleng); return AnalitzadorSintactic::FI_ITEMIZE;}
"\\begin{array}"                {sum(car,yyleng); return AnalitzadorSintactic::INICI_ARRAY;}
"\\end{array}"                  {sum(car,yyleng); return AnalitzadorSintactic::FI_ARRAY;}
"\\begin{eqnarray}"             {sum(car,yyleng); return AnalitzadorSintactic::INICI_EQARRAY;}
"\\end{eqnarray}"               {sum(car,yyleng); return AnalitzadorSintactic::FI_EQARRAY;}
"\\begin{theorem}"              {sum(car,yyleng); return AnalitzadorSintactic::INICI_TEOREMA;}
"\\end{theorem}"                {sum(car,yyleng); return AnalitzadorSintactic::FI_TEOREMA;}
"\\begin{center}"               {sum(car,yyleng); return AnalitzadorSintactic::INICI_TEXT_CENTRAT;}
"\\end{center}"                 {sum(car,yyleng); return AnalitzadorSintactic::FI_TEXT_CENTRAT;}
"\\begin{flushleft}"            {sum(car,yyleng); return AnalitzadorSintactic::INICI_TEXT_ESQ;}
"\\end{flushleft}"              {sum(car,yyleng); return AnalitzadorSintactic::FI_TEXT_ESQ;}
"\\begin{flushright}"           {sum(car,yyleng); return AnalitzadorSintactic::INICI_TEXT_DRETA;}
"\\end{flushright}"             {sum(car,yyleng); return AnalitzadorSintactic::FI_TEXT_DRETA;}
"\\begin{verse}"                {sum(car,yyleng); return AnalitzadorSintactic::INICI_VERS;}
"\\end{verse}"                  {sum(car,yyleng); return AnalitzadorSintactic::FI_VERS;}
"\\begin{tabbing}"              {sum(car,yyleng); return AnalitzadorSintactic::INICI_TABBING;}
"\\end{tabbing}"                {sum(car,yyleng); return AnalitzadorSintactic::FI_TABBING;}
"\\begin{thebibliography}"      {sum(car,yyleng); return AnalitzadorSintactic::INICI_BIBLIOGRAFIA;}
"\\end{thebibliography}"        {sum(car,yyleng); return AnalitzadorSintactic::FI_BIBLIOGRAFIA;}
"\\begin{rawhtml}"              {sum(car,yyleng); return AnalitzadorSintactic::INICI_RAWHTML;}
"\\end{rawhtml}"                {sum(car,yyleng); return AnalitzadorSintactic::FI_RAWHTML;}

"\\"                            {
                                 cout << "Avís-> linia " << num_linia <<":"<<car+1<<": Macro \\";
                                 sum(car,yyleng); BEGIN(macro_desconeguda);
                                }
<macro_desconeguda>"{"          {sum(car,yyleng);cout << " desconeguda pel traductor\n"; BEGIN(INITIAL);return AnalitzadorSintactic::PO;}
<macro_desconeguda>" "          {sum(car,yyleng);cout << " desconeguda pel traductor\n"; BEGIN(INITIAL);}
<macro_desconeguda>"\n"         {num_linia++; car=0; cout << " desconeguda pel traductor\n"; BEGIN(INITIAL);}
<macro_desconeguda>\\           {sum(car,yyleng);cout << " desconeguda pel traductor\n";BEGIN(INITIAL);return AnalitzadorSintactic::FP;}
<macro_desconeguda>"}"          {sum(car,yyleng);cout << " desconeguda pel traductor\n";BEGIN(INITIAL);return AnalitzadorSintactic::PT;}
<macro_desconeguda>[^\n \\{}]*  {sum(car,yyleng);cout << yytext; 
                                 if((strcmp(yytext,"begin")==0)||(strcmp(yytext,"end")==0)){BEGIN(entorn_macro_desconeguda);}}

<entorn_macro_desconeguda>[^\n}]*  {sum(car,yyleng);cout << yytext;}
<entorn_macro_desconeguda>"\n"     {num_linia++; car=0;}
<entorn_macro_desconeguda>"}"      {sum(car,yyleng); cout << yytext <<" desconeguda pel traductor\n";BEGIN(INITIAL);}
%%









