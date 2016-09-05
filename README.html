<h1>c-int</h1>
<p>C言語による符号なし128bit整数、符号なし256bit整数の実装の利便性/性能の改善プロジェクトです。
本成果はc-decimal等のプロジェクトで使用しています。</p>
<dl>
<dt>mg_uint128</dt>
<dd>128ビット符号なし整数</dd>
<dt>mg_uint256</dt>
<dd>256ビット符号なし整数</dd>
</dl>
<h2>mg_uint128型</h2>
<h3>定数</h3>
<h4>MG_UINT128_SIZE</h4>
<p>mg_uint128を表現するワードのサイズです。</p>
<h4>MG_UINT128_WORD_BITS</h4>
<p>mg_uint128を表現するワードのビット数です。</p>
<h3>MG_UINT128_DIGITS</h3>
<p>計算対象が下記ビット時のワード桁数を示す定数です。</p>
<dl>
<dt><code>MG_UINT128_DIGITS_32</code></dt>
<dd>32bit時のワード桁数</dd>
<dt><code>MG_UINT128_DIGITS_64</code></dt>
<dd>64bit時のワード桁数</dd>
<dt><code>MG_UINT128_DIGITS_128</code></dt>
<dd>128bit時のワード桁数</dd>
</dl>
<h3>関数</h3>
<h4>mg_uint128_set_zero()</h4>
<p>0をセットします。</p>
<dl>
<dt><code>/*out*/ mg_uint128 *dest</code></dt>
<dd>値をセットされるオブジェクト</dd>
<dt>戻り値(<code>void</code>)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_set()</h4>
<p>64bit符号なし整数をセットします。</p>
<dl>
<dt><code>/*out*/ mg_uint128 *dest</code></dt>
<dd>値をセットされるオブジェクト</dd>
<dt><code>uint64_t value</code></dt>
<dd>セットする値</dd>
<dt>戻り値(<code>void</code>)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_set_bit()</h4>
<p>指定したビットに1を立てます。</p>
<dl>
<dt><code>/*out*/ mg_uint128 *dest</code></dt>
<dd>値をセットされるオブジェクト</dd>
<dt><code>int bit_index</code></dt>
<dd>ビットを立てるビットのインデックス</dd>
<dt>戻り値(<code>void</code>)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_get_uint64()</h4>
<p>64bit符号なし整数を取得します。</p>
<dl>
<dt><code>const mg_uint128 *value</code></dt>
<dd>値を取得するオブジェクト</dd>
<dt>戻り値(<code>uint64_t</code>)</dt>
<dd>取得される64bit符号なし整数</dd>
</dl>
<h4>mg_uint128_is_zero()</h4>
<p>値がゼロであるかどうか判定します。</p>
<dl>
<dt><code>const mg_uint128 *value</code></dt>
<dd>値を判定するオブジェクト</dd>
<dt>戻り値(<code>int</code>)</dt>
<dd>0でない場合は0、それ以外の場合は1を返す。</dd>
</dl>
<h4>mg_uint128_compare()</h4>
<p>値を比較し、大小一致を示す値を返します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>値を判定するオブジェクト</dd>
<dt><code>const mg_uint128 *op</code></dt>
<dd>値を判定するオブジェクト</dd>
<dt>戻り値(<code>int</code>)</dt>
<dd><code>op1 &lt; op2: -1, op1 == op2: 0, op1 &gt; op2: 1</code></dd>
</dl>
<h4>mg_uint128_swap()</h4>
<p>値を交換します。</p>
<dl>
<dt><code>/*out*/ mg_uint128 **a</code></dt>
<dd>値を交換するオブジェクトが入った変数のポインタ</dd>
<dt><code>/*out*/ mg_uint128 **b</code></dt>
<dd>値を交換するオブジェクトが入った変数のポインタ</dd>
<dt>戻り値('void')</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_neg()</h4>
<p>値を2の補数化します。
(符号なし整数ですが符号の反転です・・・)</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>符号を反転するオブジェクト</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>符号を反転した値を格納するオブジェクト</dd>
<dt>戻り値('void')</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_add()</h4>
<p>値を加算します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>加算する値</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>加算する値</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>加算した結果を格納するオブジェクト</dd>
<dt>戻り値('int')</dt>
<dd>オーバーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint128_sub()</h4>
<p>値を減算します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>減算元の値</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>減算する値</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>減算した結果を格納するオブジェクト</dd>
<dt>戻り値(int)</dt>
<dd>アンダーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint128_mul()</h4>
<p>値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。
乗算結果が128bitの範囲に収まらない場合、
戻り値としてオーバーフローを返します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>乗数1</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>乗数2</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>除算結果を格納するオブジェクト</dd>
<dt>戻り値(int)</dt>
<dd>オーバーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint128_mul_1()</h4>
<dl>
<dt>値を乗算します。</dt>
<dt>乗数のワード桁数が分かっている場合、こちらを使います。</dt>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>乗数1</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>乗数2</dd>
<dt><code>/*out*/ mg_uint128 *low</code></dt>
<dd>乗算結果の下位128bit</dd>
<dt><code>/*out*/ mg_uint128 *high</code></dt>
<dd>乗算結果の上位128bit</dd>
</dl>
<p>戻り値(<code>void</code>)
:なし</p>
<h4>mg_uint128_mul_digits()</h4>
<p>値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。
乗算結果が128bitの範囲に収まらない場合、
戻り値としてオーバーフローを返します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>乗数1</dd>
<dt><code>int op1_digits</code></dt>
<dd>乗数1のワード桁数</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>乗数2</dd>
<dt><code>int op2_digits</code></dt>
<dd>乗数2のワード桁数</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>乗算結果を格納するオブジェクト</dd>
<dt>戻り値(<code>int</code>)</dt>
<dd>オーバーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint128_mul_digits_1()</h4>
<p>値を乗算します。
乗数のワード桁数が分かっている場合、こちらを使います。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>乗数1</dd>
<dt><code>int op1_digits</code></dt>
<dd>乗数1のワード桁数</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>乗数2</dd>
<dt><code>int op2_digits</code></dt>
<dd>乗数2のワード桁数</dd>
<dt><code>/*out*/ mg_uint128 *low</code></dt>
<dd>乗算結果の下位128bit</dd>
<dt><code>/*out*/ mg_uint128 *high</code></dt>
<dd>乗算結果の上位128bit</dd>
<dt>戻り値(<code>void</code>)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_div()</h4>
<p>値を除算します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>被除数</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>除数</dd>
<dt><code>/*out*/mg_uint128 *quotient</code></dt>
<dd>商を格納するオブジェクト</dd>
<dt><code>/*out*/mg_uint128 *reminder</code></dt>
<dd>余りを格納するオブジェクト</dd>
<dt>戻り値(<code>int</code>)</dt>
<dd>正常終了の場合: 0, ゼロによる除算の場合: 1</dd>
</dl>
<h4>mg_uint128_and()</h4>
<p>値のビット論理積を取ります。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットの論理積を取る値</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>ビットの論理積を取る値</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト</dd>
<dt>戻り値(void)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_or()</h4>
<p>値のビット論理和を取ります。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットの論理和を取る値</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>ビットの論理和を取る値</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint128_xor()</h4>
<p>値のビット排他的論理和を取ります。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットを排他的論理和を取る値</dd>
<dt><code>const mg_uint128 *op2</code></dt>
<dd>ビットを排他的論理和を取る値</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint128_not()</h4>
<p>値のビットを否定します。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットを否定する値</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト</dd>
<dt>戻り値(void)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_left_shift()</h4>
<p>値のビットを左シフトします。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットシフトを行う値</dd>
<dt><code>int shift</code></dt>
<dd>シフトさせる値(0~127)</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト</dd>
<dt>戻り値(void)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_left_shift_small()</h4>
<p>値のビットを左シフトします。
シフトするビット数が1ワードを超えないような小さいシフト専用です。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットシフトを行う値</dd>
<dt><code>int shift</code></dt>
<dd>シフトさせる値(0~31)</dd>
<dd>
<code>/*out*/ mg_uint128 *ret</code></dd>
<dd>結果を格納するオブジェクト</dd>
<dt>戻り値(void)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_right_shift()</h4>
<p>値のビットを右シフトします。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットシフトを行う値</dd>
<dt><code>int shift</code></dt>
<dd>シフトさせる値(0~127)</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint128_right_shift_small()</h4>
<p>値のビットを右シフトします。
シフトするビット数が1ワードを超えないような小さいシフト専用です。</p>
<dl>
<dt><code>const mg_uint128 *op1</code></dt>
<dd>ビットシフトを行う値</dd>
<dt><code>int shift</code></dt>
<dd>シフトさせる値(0~31)</dd>
<dt><code>/*out*/ mg_uint128 *ret</code></dt>
<dd>結果を格納するオブジェクト</dd>
<dt>戻り値(void)</dt>
<dd>なし</dd>
</dl>
<h4>mg_uint128_get_bit_size()</h4>
<dl>
<dt><code>const mg_uint128 *value</code></dt>
<dd>ビット数を計算する値</dd>
<dt>戻り値(int)</dt>
<dd>valueで指し示すオブジェクトのビット桁数</dd>
</dl>
<h2>mg_uint256型</h2>
<h4>mg_uint256_set_zero()</h4>
<p>256ビット符号なし整数型へ0をセットします。</p>
<dl>
<dt><code>/*out*/ mg_uint256 *dest</code></dt>
<dd>値をセットされるオブジェクト
戻り値(<code>void</code>)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_set()</h4>
<p>256ビット符号なし整数型へ64bit符号なし整数をセットします。</p>
<dl>
<dt><code>/*out*/ mg_uint256 *dest</code></dt>
<dd>値をセットされるオブジェクト
<code>uint64_t value</code></dd>
<dd>セットする値
戻り値(<code>void</code>)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_set_bit()</h4>
<p>256ビット符号なし整数型へ指定したビットに1を立てます。</p>
<dl>
<dt><code>/*out*/ mg_uint256 *dest</code></dt>
<dd>値をセットされるオブジェクト
<code>int bit_index</code></dd>
<dd>ビットを立てるビットのインデックス
戻り値(<code>void</code>)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_get_uint64()</h4>
<p>256ビット符号なし整数型から64bit符号なし整数を取得します。</p>
<dl>
<dt><code>const mg_uint256 *value</code></dt>
<dd>値をセットされるオブジェクト
戻り値(<code>uint64_t</code>)</dd>
<dd>取得される64bit符号なし整数</dd>
</dl>
<h4>mg_uint256_is_zero()</h4>
<p>256ビット符号なし整数型がゼロであるかどうか判定します。</p>
<dl>
<dt><code>const mg_uint256 *value</code></dt>
<dd>値を判定するオブジェクト
戻り値(<code>int</code>)</dd>
<dd>0でない場合は0、それ以外の場合は1を返す。</dd>
</dl>
<h4>mg_uint256_compare()</h4>
<p>256ビット符号なし整数型がゼロであるかどうか判定します。</p>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>値を判定するオブジェクト
<code>const mg_uint256 *op</code></dd>
<dd>値を判定するオブジェクト
戻り値(<code>int</code>)</dd>
<dd><code>op1 &lt; op2: -1, op1 == op2: 0, op1 &gt; op2: 1</code></dd>
</dl>
<h4>mg_uint256_swap()</h4>
<p>256ビット符号なし整数型を交換します。</p>
<dl>
<dt><code>/*out*/ mg_uint256 **a</code></dt>
<dd>値を交換するオブジェクトが入った変数のポインタ
<code>/*out*/ mg_uint256 **b</code></dd>
<dd>値を交換するオブジェクトが入った変数のポインタ
戻り値('void')</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_neg()</h4>
<p>256ビット符号なし整数型を2の補数化します。
(符号なし整数ですが符号の反転です・・・)</p>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>符号を反転するオブジェクト
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>符号を反転した値を格納するオブジェクト
戻り値('void')</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_add()</h4>
<p>256ビット符号なし整数型を加算します。</p>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>加算する値
<code>const mg_uint256 *op2</code></dd>
<dd>加算する値
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>加算した結果を格納するオブジェクト
戻り値('int')</dd>
<dd>オーバーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint256_sub()</h4>
<p>256ビット符号なし整数型を減算します。</p>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>減算元の値
<code>const mg_uint256 *op2</code></dd>
<dd>減算する値
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>減算した結果を格納するオブジェクト
戻り値(int)</dd>
<dd>アンダーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint256_mul()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dt>:</dt>
<dt><code>const mg_uint256 *op2</code></dt>
<dt>:</dt>
<dt><code>/*out*/ mg_uint256 *ret</code></dt>
<dt>:</dt>
<dt>戻り値(int)</dt>
<dd>オーバーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint256_mul_1()</h4>
<p><code>const mg_uint256 *op1</code>
:
<code>const mg_uint256 *op2</code>
:
<code>/*out*/ mg_uint256 *low</code>
:
<code>/*out*/ mg_uint256 *high</code>
:
戻り値(<code>void</code>)
:なし</p>
<h4>mg_uint256_mul_digits()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dt>:</dt>
<dt><code>int op1_digits</code></dt>
<dt>:</dt>
<dt><code>const mg_uint256 *op2</code></dt>
<dt>:</dt>
<dt><code>int op2_digits</code></dt>
<dt>:</dt>
<dt><code>/*out*/ mg_uint256 *ret</code></dt>
<dt>:</dt>
<dt>戻り値(<code>int</code>)</dt>
<dd>オーバーフロー時: 1, それ以外: 0</dd>
</dl>
<h4>mg_uint256_mul_digits_1()</h4>
<p><code>const mg_uint256 *op1</code>
:
<code>int op1_digits</code>
:
<code>const mg_uint256 *op2</code>
:
<code>int op2_digits</code>
:
<code>/*out*/ mg_uint256 *low</code>
:
<code>/*out*/ mg_uint256 *high</code>
:
戻り値(<code>void</code>)
:なし</p>
<h4>mg_uint256_div()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dt>:</dt>
<dt><code>const mg_uint256 *op2</code></dt>
<dt>:</dt>
<dt><code>/*out*/mg_uint256 *quotient</code></dt>
<dt>:</dt>
<dt><code>/*out*/mg_uint256 *reminder</code></dt>
<dt>:</dt>
<dt>戻り値(<code>int</code>)</dt>
<dd>正常終了の場合: 0, ゼロによる除算の場合: 1</dd>
</dl>
<h4>mg_uint256_and()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>const mg_uint256 *op2</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_or()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>const mg_uint256 *op2</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_xor()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>const mg_uint256 *op2</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_not()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_left_shift()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>int shift</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_left_shift_small()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>int shift</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_right_shift()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>int shift</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_right_shift_small()</h4>
<dl>
<dt><code>const mg_uint256 *op1</code></dt>
<dd>
<code>int shift</code></dd>
<dd>
<code>/*out*/ mg_uint256 *ret</code></dd>
<dd>結果を格納するオブジェクト
戻り値(void)</dd>
<dd>なし</dd>
</dl>
<h4>mg_uint256_get_bit_size()</h4>
<dl>
<dt><code>const mg_uint256 *value</code></dt>
<dd>
戻り値(int)</dd>
<dd>valueで指し示すオブジェクトのビット桁数</dd>
</dl>
