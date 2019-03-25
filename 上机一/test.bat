@Echo Off
Set /p yearmonthday=ÊäÈë£º ³öÉúÄêÔÂÈÕ £¨ÀıÈç 19970731£©

Set year=%yearmonthday:~0,4%
Set monthday=%yearmonthday:~4,4%
Set /a mod=%year%%%12

if %mod%==0 Echo ÄãÊôºï
if %mod%==1 Echo ÄãÊô¼¦
if %mod%==2 Echo ÄãÊô¹·
if %mod%==3 Echo ÄãÊôÖí
if %mod%==4 Echo ÄãÊôÊó
if %mod%==5 Echo ÄãÊôÅ£
if %mod%==6 Echo ÄãÊô»¢
if %mod%==7 Echo ÄãÊôÍÃ
if %mod%==8 Echo ÄãÊôÁú
if %mod%==9 Echo ÄãÊôÉß
if %mod%==10 Echo ÄãÊôÂí
if %mod%==11 Echo ÄãÊôÑò



if "%monthday%" LEQ "0119" echo Ä¦ôÉ×ù
if "%monthday%" GEQ "0120" if "%monthday%" LEQ "0218" echo Ë®Æ¿×ù
if "%monthday%" GEQ "0219" if "%monthday%" LEQ "0320" echo Ë«Óã×ù
if "%monthday%" GEQ "0321" if "%monthday%" LEQ "0419" echo °×Ñò×ù
if "%monthday%" GEQ "0420" if "%monthday%" LEQ "0520" echo ½ğÅ£×ù
if "%monthday%" GEQ "0521" if "%monthday%" LEQ "0621" echo Ë«×Ó×ù
if "%monthday%" GEQ "0622" if "%monthday%" LEQ "0722" echo ¾ŞĞ·×ù
if "%monthday%" GEQ "0723" if "%monthday%" LEQ "0822" echo Ê¨×Ó×ù
if "%monthday%" GEQ "0823" if "%monthday%" LEQ "0922" echo ´¦Å®×ù
if "%monthday%" GEQ "0923" if "%monthday%" LEQ "1023" echo Ìì³Ó×ù
if "%monthday%" GEQ "1024" if "%monthday%" LEQ "1122" echo ÌìĞ«×ù
if "%monthday%" GEQ "0321" if "%monthday%" LEQ "0419" echo °×Ñò×ù
if "%monthday%" GEQ "1222" echo Ä¦ôÉ×ù

Pause
