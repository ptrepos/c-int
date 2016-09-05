# c-int
C言語による符号なし128bit整数、符号なし256bit整数の実装の利便性/性能の改善プロジェクトです。
本成果はc-decimal等のプロジェクトで使用しています。

mg_uint128
: 128ビット符号なし整数

mg_uint256
: 256ビット符号なし整数

## mg_uint128型

### 定数

#### MG_UINT128_SIZE
mg_uint128を表現するワードのサイズです。

#### MG_UINT128_WORD_BITS
mg_uint128を表現するワードのビット数です。

#### MG_UINT128_DIGITS
計算対象が下記ビット時のワード桁数を示す定数です。

`MG_UINT128_DIGITS_32`
: 32bit時のワード桁数

`MG_UINT128_DIGITS_64`
: 64bit時のワード桁数

`MG_UINT128_DIGITS_128`
: 128bit時のワード桁数

### 関数

#### mg_uint128_set_zero()
0をセットします。

`/*out*/ mg_uint128 *dest`
: 値をセットされるオブジェクト

戻り値(`void`)
: なし

#### mg_uint128_set()
64bit符号なし整数をセットします。

`/*out*/ mg_uint128 *dest`
: 値をセットされるオブジェクト

`uint64_t value`
: セットする値

戻り値(`void`)
: なし

#### mg_uint128_set_bit()
指定したビットに1を立てます。

`/*out*/ mg_uint128 *dest`
: 値をセットされるオブジェクト

`int bit_index`
: ビットを立てるビットのインデックス

戻り値(`void`)
: なし

#### mg_uint128_get_uint64()
64bit符号なし整数を取得します。

`const mg_uint128 *value`
: 値を取得するオブジェクト

戻り値(`uint64_t`)
: 取得される64bit符号なし整数


#### mg_uint128_is_zero()
値がゼロであるかどうか判定します。

`const mg_uint128 *value`
: 値を判定するオブジェクト

戻り値(`int`)
: 0でない場合は0、それ以外の場合は1を返す。

#### mg_uint128_compare()
値を比較し、大小一致を示す値を返します。

`const mg_uint128 *op1`
: 値を判定するオブジェクト

`const mg_uint128 *op`
: 値を判定するオブジェクト

戻り値(`int`)
: `op1 < op2: -1, op1 == op2: 0, op1 > op2: 1`

#### mg_uint128_swap()
値を交換します。

`/*out*/ mg_uint128 **a`
: 値を交換するオブジェクトが入った変数のポインタ

`/*out*/ mg_uint128 **b`
: 値を交換するオブジェクトが入った変数のポインタ

戻り値('void')
: なし

#### mg_uint128_neg()
値を2の補数化します。
(符号なし整数ですが符号の反転です・・・)

`const mg_uint128 *op1`
: 符号を反転するオブジェクト

`/*out*/ mg_uint128 *ret`
: 符号を反転した値を格納するオブジェクト

戻り値('void')
: なし

#### mg_uint128_add()
値を加算します。

`const mg_uint128 *op1`
: 加算する値

`const mg_uint128 *op2`
: 加算する値

`/*out*/ mg_uint128 *ret`
: 加算した結果を格納するオブジェクト

戻り値('int')
: オーバーフロー時: 1, それ以外: 0

#### mg_uint128_sub()
値を減算します。

`const mg_uint128 *op1`
: 減算元の値

`const mg_uint128 *op2`
: 減算する値

`/*out*/ mg_uint128 *ret`
: 減算した結果を格納するオブジェクト

戻り値(int)
: アンダーフロー時: 1, それ以外: 0

#### mg_uint128_mul()
値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。
乗算結果が128bitの範囲に収まらない場合、
戻り値としてオーバーフローを返します。

`const mg_uint128 *op1`
: 乗数1

`const mg_uint128 *op2`
: 乗数2

`/*out*/ mg_uint128 *ret`
: 除算結果を格納するオブジェクト

戻り値(int)
: オーバーフロー時: 1, それ以外: 0

#### mg_uint128_mul_1()
値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。
`const mg_uint128 *op1`
: 乗数1

`const mg_uint128 *op2`
: 乗数2

`/*out*/ mg_uint128 *low`
: 乗算結果の下位128bit

`/*out*/ mg_uint128 *high`
: 乗算結果の上位128bit

戻り値(`void`)
:なし

#### mg_uint128_mul_digits()
値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。
乗算結果が128bitの範囲に収まらない場合、
戻り値としてオーバーフローを返します。

`const mg_uint128 *op1`
: 乗数1

`int op1_digits`
: 乗数1のワード桁数

`const mg_uint128 *op2`
: 乗数2

`int op2_digits`
: 乗数2のワード桁数

`/*out*/ mg_uint128 *ret`
: 乗算結果を格納するオブジェクト

戻り値(`int`)
: オーバーフロー時: 1, それ以外: 0

#### mg_uint128_mul_digits_1()
値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。

`const mg_uint128 *op1`
: 乗数1

`int op1_digits`
: 乗数1のワード桁数

`const mg_uint128 *op2`
: 乗数2

`int op2_digits`
: 乗数2のワード桁数

`/*out*/ mg_uint128 *low`
: 乗算結果の下位128bit

`/*out*/ mg_uint128 *high`
: 乗算結果の上位128bit

戻り値(`void`)
: なし

#### mg_uint128_div()
値を除算します。

`const mg_uint128 *op1`
: 被除数

`const mg_uint128 *op2`
: 除数

`/*out*/mg_uint128 *quotient`
: 商を格納するオブジェクト

`/*out*/mg_uint128 *reminder`
: 余りを格納するオブジェクト

戻り値(`int`)
: 正常終了の場合: 0, ゼロによる除算の場合: 1

#### mg_uint128_and()
値のビット論理積を取ります。

`const mg_uint128 *op1`
: ビットの論理積を取る値

`const mg_uint128 *op2`
: ビットの論理積を取る値

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint128_or()
値のビット論理和を取ります。

`const mg_uint128 *op1`
: ビットの論理和を取る値

`const mg_uint128 *op2`
: ビットの論理和を取る値

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint128_xor()
値のビット排他的論理和を取ります。

`const mg_uint128 *op1`
: ビットを排他的論理和を取る値

`const mg_uint128 *op2`
: ビットを排他的論理和を取る値

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint128_not()
値のビットを否定します。

`const mg_uint128 *op1`
: ビットを否定する値

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint128_left_shift()
値のビットを左シフトします。

`const mg_uint128 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~127)

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint128_left_shift_small()
値のビットを左シフトします。
シフトするビット数が1ワードを超えないような小さいシフト専用です。

`const mg_uint128 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~31)
: 
`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし


#### mg_uint128_right_shift()
値のビットを右シフトします。

`const mg_uint128 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~127)

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint128_right_shift_small()
値のビットを右シフトします。
シフトするビット数が1ワードを超えないような小さいシフト専用です。

`const mg_uint128 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~31)

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint128_get_bit_size()

`const mg_uint128 *value`
: ビット数を計算する値

戻り値(int)
: valueで指し示すオブジェクトのビット桁数

## mg_uint256型

#### mg_uint256_set_zero()
256ビット符号なし整数型へ0をセットします。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト
戻り値(`void`)
: なし

#### mg_uint256_set()
256ビット符号なし整数型へ64bit符号なし整数をセットします。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト
`uint64_t value`
: セットする値
戻り値(`void`)
: なし

#### mg_uint256_set_bit()
256ビット符号なし整数型へ指定したビットに1を立てます。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト
`int bit_index`
: ビットを立てるビットのインデックス
戻り値(`void`)
: なし

#### mg_uint256_get_uint64()
256ビット符号なし整数型から64bit符号なし整数を取得します。

`const mg_uint256 *value`
: 値をセットされるオブジェクト
戻り値(`uint64_t`)
: 取得される64bit符号なし整数


#### mg_uint256_is_zero()
256ビット符号なし整数型がゼロであるかどうか判定します。

`const mg_uint256 *value`
: 値を判定するオブジェクト
戻り値(`int`)
: 0でない場合は0、それ以外の場合は1を返す。

#### mg_uint256_compare()
256ビット符号なし整数型がゼロであるかどうか判定します。

`const mg_uint256 *op1`
: 値を判定するオブジェクト
`const mg_uint256 *op`
: 値を判定するオブジェクト
戻り値(`int`)
: `op1 < op2: -1, op1 == op2: 0, op1 > op2: 1`

#### mg_uint256_swap()
256ビット符号なし整数型を交換します。

`/*out*/ mg_uint256 **a`
: 値を交換するオブジェクトが入った変数のポインタ
`/*out*/ mg_uint256 **b`
: 値を交換するオブジェクトが入った変数のポインタ
戻り値('void')
: なし

#### mg_uint256_neg()
256ビット符号なし整数型を2の補数化します。
(符号なし整数ですが符号の反転です・・・)

`const mg_uint256 *op1`
: 符号を反転するオブジェクト
`/*out*/ mg_uint256 *ret`
: 符号を反転した値を格納するオブジェクト
戻り値('void')
: なし

#### mg_uint256_add()
256ビット符号なし整数型を加算します。

`const mg_uint256 *op1`
: 加算する値
`const mg_uint256 *op2`
: 加算する値
`/*out*/ mg_uint256 *ret`
: 加算した結果を格納するオブジェクト
戻り値('int')
: オーバーフロー時: 1, それ以外: 0

#### mg_uint256_sub()
256ビット符号なし整数型を減算します。

`const mg_uint256 *op1`
: 減算元の値
`const mg_uint256 *op2`
: 減算する値
`/*out*/ mg_uint256 *ret`
: 減算した結果を格納するオブジェクト
戻り値(int)
: アンダーフロー時: 1, それ以外: 0

#### mg_uint256_mul()
`const mg_uint256 *op1`
:
`const mg_uint256 *op2`
:
`/*out*/ mg_uint256 *ret`
:
戻り値(int)
: オーバーフロー時: 1, それ以外: 0

#### mg_uint256_mul_1()
`const mg_uint256 *op1`
:
`const mg_uint256 *op2`
:
`/*out*/ mg_uint256 *low`
:
`/*out*/ mg_uint256 *high`
:
戻り値(`void`)
:なし

#### mg_uint256_mul_digits()
`const mg_uint256 *op1`
:
`int op1_digits`
:
`const mg_uint256 *op2`
:
`int op2_digits`
:
`/*out*/ mg_uint256 *ret`
:
戻り値(`int`)
: オーバーフロー時: 1, それ以外: 0

#### mg_uint256_mul_digits_1()
`const mg_uint256 *op1`
:
`int op1_digits`
:
`const mg_uint256 *op2`
:
`int op2_digits`
:
`/*out*/ mg_uint256 *low`
:
`/*out*/ mg_uint256 *high`
:
戻り値(`void`)
:なし

#### mg_uint256_div()
`const mg_uint256 *op1`
:
`const mg_uint256 *op2`
:
`/*out*/mg_uint256 *quotient`
:
`/*out*/mg_uint256 *reminder`
:
戻り値(`int`)
: 正常終了の場合: 0, ゼロによる除算の場合: 1

#### mg_uint256_and()

`const mg_uint256 *op1`
: 
`const mg_uint256 *op2`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_or()

`const mg_uint256 *op1`
: 
`const mg_uint256 *op2`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_xor()

`const mg_uint256 *op1`
: 
`const mg_uint256 *op2`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_not()

`const mg_uint256 *op1`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_left_shift()

`const mg_uint256 *op1`
: 
`int shift`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_left_shift_small()

`const mg_uint256 *op1`
: 
`int shift`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし


#### mg_uint256_right_shift()

`const mg_uint256 *op1`
: 
`int shift`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_right_shift_small()

`const mg_uint256 *op1`
: 
`int shift`
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト
戻り値(void)
: なし

#### mg_uint256_get_bit_size()

`const mg_uint256 *value`
: 
戻り値(int)
: valueで指し示すオブジェクトのビット桁数
