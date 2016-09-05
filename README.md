# c-int
C言語による符号なし128bit整数、符号なし256bit整数の実装の利便性/性能の改善プロジェクトです。
本成果はc-decimal等のプロジェクトで使用しています。

基本はC言語ですが一部nasmによるアセンブラコードも含まれます。
また、C99以降の記法に依存しており。
gccでは-std=c99オプションを付ける必用があります。

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
```
void mg_uint128_set_zero(
		mg_uint128 *dest);
```

0をセットします。

`/*out*/ mg_uint128 *dest`
: 値をセットされるオブジェクト

戻り値(`void`)
: なし

#### mg_uint128_set()
```
void mg_uint128_set(
		mg_uint128 *dest,
		uint64_t value);
```

64bit符号なし整数をセットします。

`/*out*/ mg_uint128 *dest`
: 値をセットされるオブジェクト

`uint64_t value`
: セットする値

戻り値(`void`)
: なし

#### mg_uint128_set_bit()
```
void mg_uint128_set_bit(
		mg_uint128 *dest,
		int bit_index);
```

指定したビットに1を立てます。

`/*out*/ mg_uint128 *dest`
: 値をセットされるオブジェクト

`int bit_index`
: ビットを立てるビットのインデックス

戻り値(`void`)
: なし

#### mg_uint128_get_uint64()
```
uint64_t mg_uint128_get_uint64(
		const mg_uint128 *value);
```

64bit符号なし整数を取得します。

`const mg_uint128 *value`
: 値を取得するオブジェクト

戻り値(`uint64_t`)
: 取得される64bit符号なし整数


#### mg_uint128_is_zero()
```
int mg_uint128_is_zero(
		const mg_uint128 *value);
```

値がゼロであるかどうか判定します。

`const mg_uint128 *value`
: 値を判定するオブジェクト

戻り値(`int`)
: 0でない場合は0、それ以外の場合は1を返す。

#### mg_uint128_compare()
```
int mg_uint128_compare(
		const mg_uint128 *value1, 
		const mg_uint128 *value2);
```

値を比較し、大小一致を示す値を返します。

`const mg_uint128 *value1`
: 値を判定するオブジェクト

`const mg_uint128 *value2`
: 値を判定するオブジェクト

戻り値(`int`)
: `op1 < op2: -1, op1 == op2: 0, op1 > op2: 1`

#### mg_uint128_swap()
```
void mg_uint128_swap(
		mg_uint128 **a, 
		mg_uint128 **b);
```

値を交換します。

`/*out*/ mg_uint128 **a`
: 値を交換するオブジェクトが入った変数のポインタ

`/*out*/ mg_uint128 **b`
: 値を交換するオブジェクトが入った変数のポインタ

戻り値('void')
: なし

#### mg_uint128_neg()
```
void mg_uint128_neg(
		const mg_uint128 *op1, 
		/*out*/mg_uint128 *ret);
```

値を2の補数化します。
(符号なし整数ですが符号の反転です・・・)

`const mg_uint128 *op1`
: 符号を反転するオブジェクト

`/*out*/ mg_uint128 *ret`
: 符号を反転した値を格納するオブジェクト

戻り値('void')
: なし

#### mg_uint128_add()
```
int mg_uint128_add(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *ret);
```

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
```
int mg_uint128_sub(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *ret);
```

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
```
int mg_uint128_mul(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *ret);
```

値を乗算します。
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
```
void mg_uint128_mul_1(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *_lo, 
		/*out*/mg_uint128 *_hi);
```

値を乗算します。
`const mg_uint128 *op1`
: 乗数1

`const mg_uint128 *op2`
: 乗数2

`/*out*/ mg_uint128 *low`
: 乗算結果の下位128bit

`/*out*/ mg_uint128 *high`
: 乗算結果の上位128bit

戻り値(`void`)
: なし

#### mg_uint128_mul_digits()
```
int mg_uint128_mul_digits(
		const mg_uint128 *op1, 
		int op1_digits, 
		const mg_uint128 *op2, 
		int op2_digits, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_mul_digits_1(
		const mg_uint128 *op1, 
		int op1_words, 
		const mg_uint128 *op2, 
		int op2_words, 
		/*out*/mg_uint128 *low, 
		/*out*/mg_uint128 *high);
```

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
```
int mg_uint128_div(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *quotient, 
		/*out*/mg_uint128 *reminder);
```

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
```
void mg_uint128_and(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_or(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_xor(
		const mg_uint128 *op1, 
		const mg_uint128 *op2, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_not(
		const mg_uint128 *op1, 
		/*out*/mg_uint128 *ret);
```

値のビットを否定します。

`const mg_uint128 *op1`
: ビットを否定する値

`/*out*/ mg_uint128 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint128_left_shift()
```
void mg_uint128_left_shift(
		const mg_uint128 *op1, 
		int shift, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_left_shift_small(
		const mg_uint128 *op1, 
		int shift, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_right_shift(
		const mg_uint128 *op1, 
		int shift, 
		/*out*/mg_uint128 *ret);
```

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
```
void mg_uint128_right_shift_small(
		const mg_uint128 *op1, 
		int shift, 
		/*out*/mg_uint128 *ret);
```

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
```
int mg_uint128_get_bit_size(
		const mg_uint128 *value);
```

`const mg_uint128 *value`
: ビット数を計算する値

戻り値(int)
: valueで指し示すオブジェクトのビット桁数

## mg_uint256型


### 定数

#### MG_UINT256_SIZE
mg_uint256を表現するワードのサイズです。

#### MG_UINT256_WORD_BITS
mg_uint256を表現するワードのビット数です。

#### MG_UINT256_DIGITS
計算対象が下記ビット時のワード桁数を示す定数です。

`MG_UINT256_DIGITS_32`
: 32bit時のワード桁数

`MG_UINT256_DIGITS_64`
: 64bit時のワード桁数

`MG_UINT256_DIGITS_128`
: 128bit時のワード桁数

`MG_UINT256_DIGITS_192`
: 192bit時のワード桁数

`MG_UINT256_DIGITS_256`
: 256bit時のワード桁数

### 関数

#### mg_uint256_set_zero()
```
void mg_uint256_set_zero(
		mg_uint256 *dest);
```

0をセットします。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト

戻り値(`void`)
: なし

#### mg_uint256_set()
```
void mg_uint256_set(
		mg_uint256 *dest,
		uint64_t value);
```

64bit符号なし整数をセットします。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト

`uint64_t value`
: セットする値

戻り値(`void`)
: なし

#### mg_uint256_set128()
```
void mg_uint256_set128(
		mg_uint256 *dest, 
		const mg_uint128 *value);
```

128bit符号なし整数をセットします。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト

`const mg_uint128 *value`
: セットする値

戻り値(`void`)
: なし

#### mg_uint256_set_bit()
```
void mg_uint256_set_bit(
		mg_uint256 *dest, 
		int bit_index);
```

指定したビットに1を立てます。

`/*out*/ mg_uint256 *dest`
: 値をセットされるオブジェクト

`int bit_index`
: ビットを立てるビットのインデックス

戻り値(`void`)
: なし

#### mg_uint256_get_uint64()
```
uint64_t mg_uint256_get_uint64(
		const mg_uint256 *value);
```

64bit符号なし整数を取得します。

`const mg_uint256 *value`
: 値を取得するオブジェクト

戻り値(`uint64_t`)
: 取得される64bit符号なし整数

#### mg_uint256_get_uint128()
```
void mg_uint256_get_uint128(
		const mg_uint256 *value, 
		mg_uint128 *ret);
```

128bit符号なし整数を取得します。

`const mg_uint256 *value`
: 値を取得するオブジェクト

`mg_uint128 *ret`
: 取得した128bit符号無し整数

戻り値(`void`)
: なし

#### mg_uint256_is_zero()
```
int mg_uint256_is_zero(
		const mg_uint256 *value);
```

値がゼロであるかどうか判定します。

`const mg_uint256 *value`
: 値を判定するオブジェクト

戻り値(`int`)
: 0でない場合は0、それ以外の場合は1を返す。

#### mg_uint256_compare()
```
int mg_uint256_compare(
		const mg_uint256 *value1, 
		const mg_uint256 *value2);
```

値を比較し、大小一致を示す値を返します。

`const mg_uint256 *value1`
: 値を判定するオブジェクト

`const mg_uint256 *value2`
: 値を判定するオブジェクト

戻り値(`int`)
: `op1 < op2: -1, op1 == op2: 0, op1 > op2: 1`

#### mg_uint256_swap()
```
void mg_uint256_swap(
		mg_uint256 **a, 
		mg_uint256 **b);
```

値を交換します。

`/*out*/ mg_uint256 **a`
: 値を交換するオブジェクトが入った変数のポインタ

`/*out*/ mg_uint256 **b`
: 値を交換するオブジェクトが入った変数のポインタ

戻り値('void')
: なし

#### mg_uint256_neg()
```
void mg_uint256_neg(
		const mg_uint256 *op1, 
		/*out*/mg_uint256 *ret);
```

値を2の補数化します。
(符号なし整数ですが符号の反転です・・・)

`const mg_uint256 *op1`
: 符号を反転するオブジェクト

`/*out*/ mg_uint256 *ret`
: 符号を反転した値を格納するオブジェクト

戻り値('void')
: なし

#### mg_uint256_add()
```
int mg_uint256_add(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *ret);
```

値を加算します。

`const mg_uint256 *op1`
: 加算する値

`const mg_uint256 *op2`
: 加算する値

`/*out*/ mg_uint256 *ret`
: 加算した結果を格納するオブジェクト

戻り値('int')
: オーバーフロー時: 1, それ以外: 0

#### mg_uint256_sub()
```
int mg_uint256_sub(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *ret);
```

値を減算します。

`const mg_uint256 *op1`
: 減算元の値

`const mg_uint256 *op2`
: 減算する値

`/*out*/ mg_uint256 *ret`
: 減算した結果を格納するオブジェクト

戻り値(int)
: アンダーフロー時: 1, それ以外: 0

#### mg_uint256_mul()
```
int mg_uint256_mul(
		const mg_uint256 *op1,
		const mg_uint256 *op2,
		/*out*/mg_uint256 *ret);
```

値を乗算します。
乗算結果が256bitの範囲に収まらない場合、
戻り値としてオーバーフローを返します。

`const mg_uint256 *op1`
: 乗数1

`const mg_uint256 *op2`
: 乗数2

`/*out*/ mg_uint256 *ret`
: 除算結果を格納するオブジェクト

戻り値(int)
: オーバーフロー時: 1, それ以外: 0

#### mg_uint256_mul_1()
```
void mg_uint256_mul_1(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *low, 
		/*out*/mg_uint256 *high);
```

値を乗算します。

`const mg_uint256 *op1`
: 乗数1

`const mg_uint256 *op2`
: 乗数2

`/*out*/ mg_uint256 *low`
: 乗算結果の下位256bit

`/*out*/ mg_uint256 *high`
: 乗算結果の上位256bit

戻り値(`void`)
: なし

#### mg_uint256_mul_digits()
```
int mg_uint256_mul_digits(
		const mg_uint256 *op1, 
		int op1_digits, 
		const mg_uint256 *op2, 
		int op2_digits, 
		/*out*/mg_uint256 *ret);
```

値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。
乗算結果が256bitの範囲に収まらない場合、
戻り値としてオーバーフローを返します。

`const mg_uint256 *op1`
: 乗数1

`int op1_digits`
: 乗数1のワード桁数

`const mg_uint256 *op2`
: 乗数2

`int op2_digits`
: 乗数2のワード桁数

`/*out*/ mg_uint256 *ret`
: 乗算結果を格納するオブジェクト

戻り値(`int`)
: オーバーフロー時: 1, それ以外: 0

#### mg_uint256_mul_digits_1()
```
void mg_uint256_mul_digits_1(
		const mg_uint256 *op1, 
		int op1_digits, 
		const mg_uint256 *op2, 
		int op2_digits, 
		/*out*/mg_uint256 *low, 
		/*out*/mg_uint256 *high);
```

値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。

`const mg_uint256 *op1`
: 乗数1

`int op1_digits`
: 乗数1のワード桁数

`const mg_uint256 *op2`
: 乗数2

`int op2_digits`
: 乗数2のワード桁数

`/*out*/ mg_uint256 *low`
: 乗算結果の下位256bit

`/*out*/ mg_uint256 *high`
: 乗算結果の上位256bit

戻り値(`void`)
: なし

#### mg_uint256_div()
```
int mg_uint256_div(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *quotient, 
		/*out*/mg_uint256 *reminder);
```

値を除算します。

`const mg_uint256 *op1`
: 被除数

`const mg_uint256 *op2`
: 除数

`/*out*/mg_uint256 *quotient`
: 商を格納するオブジェクト

`/*out*/mg_uint256 *reminder`
: 余りを格納するオブジェクト

戻り値(`int`)
: 正常終了の場合: 0, ゼロによる除算の場合: 1

#### mg_uint256_and()
```
void mg_uint256_and(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *ret);
```

値のビット論理積を取ります。

`const mg_uint256 *op1`
: ビットの論理積を取る値

`const mg_uint256 *op2`
: ビットの論理積を取る値

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_or()
```
void mg_uint256_or(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *ret);
```

値のビット論理和を取ります。

`const mg_uint256 *op1`
: ビットの論理和を取る値

`const mg_uint256 *op2`
: ビットの論理和を取る値

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_xor()
```
void mg_uint256_xor(
		const mg_uint256 *op1, 
		const mg_uint256 *op2, 
		/*out*/mg_uint256 *ret);
```

値のビット排他的論理和を取ります。

`const mg_uint256 *op1`
: ビットを排他的論理和を取る値

`const mg_uint256 *op2`
: ビットを排他的論理和を取る値

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_not()
```
void mg_uint256_not(
		const mg_uint256 *op1, 
		/*out*/mg_uint256 *ret);
```

値のビットを否定します。

`const mg_uint256 *op1`
: ビットを否定する値

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_left_shift()
```
void mg_uint256_left_shift(
		const mg_uint256 *op1, 
		int shift, 
		/*out*/mg_uint256 *ret);
```

値のビットを左シフトします。

`const mg_uint256 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~127)

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_left_shift_small()
```
void mg_uint256_left_shift_small(
		const mg_uint256 *op1, 
		int shift, 
		/*out*/mg_uint256 *ret);
```

値のビットを左シフトします。
シフトするビット数が1ワードを超えないような小さいシフト専用です。

`const mg_uint256 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~31)
: 
`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし


#### mg_uint256_right_shift()
```
void mg_uint256_right_shift(
		const mg_uint256 *op1, 
		int shift, 
		/*out*/mg_uint256 *ret);
```

値のビットを右シフトします。

`const mg_uint256 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~127)

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_right_shift_small()
```
void mg_uint256_right_shift_small(
		const mg_uint256 *op1, 
		int shift, 
		/*out*/mg_uint256 *ret);
```

値のビットを右シフトします。
シフトするビット数が1ワードを超えないような小さいシフト専用です。

`const mg_uint256 *op1`
: ビットシフトを行う値

`int shift`
: シフトさせる値(0~31)

`/*out*/ mg_uint256 *ret`
: 結果を格納するオブジェクト

戻り値(void)
: なし

#### mg_uint256_get_bit_size()
```
int mg_uint256_get_bit_size(
		const mg_uint256 *value);
```

`const mg_uint256 *value`
: ビット数を計算する値

戻り値(int)
: valueで指し示すオブジェクトのビット桁数

