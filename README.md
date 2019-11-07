# CS-30_Project2
<p class="has-line-data" data-line-start="0" data-line-end="1">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="2" data-line-end="3">Project 2: Project 3 Prep and STLs (due Monday, November 18 th at 11:59 PM)</p>
<ol>
<li class="has-line-data" data-line-start="4" data-line-end="6">We anticipate that many people working on Project 3 will spend a lot of time</li>
</ol>
<p class="has-line-data" data-line-start="6" data-line-end="7">debugging something that arises from a common novice misunderstanding. To save you that time later, we’ll give you a chance to make that mistake in a simpler context, so you can work out that issue and how it manifests itself. (It may turn out that you don’t have that misunderstanding, so you won’t have any problems during these questions. Still, keep this question in mind, because you may still make the mistake in Project 3.)</p>
<p class="has-line-data" data-line-start="8" data-line-end="9">a. Implement the removeOdds function: #include &lt;list&gt; #include &lt;vector&gt; #include &lt;algorithm&gt; #include &lt;iostream&gt; #include &lt;cassert&gt; using namespace std;</p>
<p class="has-line-data" data-line-start="10" data-line-end="11">// Remove the odd integers from li. // It is acceptable if the order of the remaining even integers is not</p>
<p class="has-line-data" data-line-start="12" data-line-end="13">// the same as in the original list. void removeOdds(list&lt;int&gt;&amp; li) { }</p>
<p class="has-line-data" data-line-start="14" data-line-end="15">void test() {</p>
<p class="has-line-data" data-line-start="16" data-line-end="17">int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 }; list&lt;int&gt; x(a, a+8); // construct x from the array assert(x.size() == 8 &amp;&amp; x.front() == 2 &amp;&amp; x.back() == 1); removeOdds(x); assert(x.size() == 4); vector&lt;int&gt; v(x.begin(), x.end()); // construct v from x sort(v.begin(), v.end()); int expect[4] = { 2, 4, 6, 8 }; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="18" data-line-end="19">assert(v[k] == expect[k]); }</p>
<p class="has-line-data" data-line-start="20" data-line-end="21">int main(){</p>
<p class="has-line-data" data-line-start="22" data-line-end="23">test(); cout &lt;&lt; “Passed” &lt;&lt; endl; return 0; }</p>
<p class="has-line-data" data-line-start="24" data-line-end="25">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="26" data-line-end="27">b. Implement the removeOdds function: #include &lt;vector&gt; #include &lt;algorithm&gt; #include &lt;iostream&gt; #include &lt;cassert&gt; using namespace std;</p>
<p class="has-line-data" data-line-start="28" data-line-end="29">// Remove the odd integers from v. // It is acceptable if the order of the remaining even integers is not</p>
<p class="has-line-data" data-line-start="30" data-line-end="31">// the same as in the original vector. void removeOdds(vector&lt;int&gt;&amp; v) { }</p>
<p class="has-line-data" data-line-start="32" data-line-end="33">void test() {</p>
<p class="has-line-data" data-line-start="34" data-line-end="35">int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 }; vector&lt;int&gt; x(a, a+8); // construct x from the array assert(x.size() == 8 &amp;&amp; x.front() == 2 &amp;&amp; x.back() == 1); removeOdds(x); assert(x.size() == 4); sort(x.begin(), x.end()); int expect[4] = { 2, 4, 6, 8 }; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="36" data-line-end="37">assert(x[k] == expect[k]); }</p>
<p class="has-line-data" data-line-start="38" data-line-end="39">int main() {</p>
<p class="has-line-data" data-line-start="40" data-line-end="41">test(); cout &lt;&lt; “Passed” &lt;&lt; endl; }</p>
<p class="has-line-data" data-line-start="42" data-line-end="43">c. Implement the removeBad function: #include &lt;list&gt; #include &lt;vector&gt; #include &lt;algorithm&gt; #include &lt;iostream&gt; #include &lt;cassert&gt; using namespace std;</p>
<p class="has-line-data" data-line-start="44" data-line-end="45">vector&lt;int&gt; destroyedOnes;</p>
<p class="has-line-data" data-line-start="46" data-line-end="47">class Movie {</p>
<p class="has-line-data" data-line-start="48" data-line-end="49">public:</p>
<p class="has-line-data" data-line-start="50" data-line-end="51">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="52" data-line-end="53">Movie(int r) : m_rating® {} ~Movie() { destroyedOnes.push_back(m_rating); } int rating() const { return m_rating; } private:</p>
<p class="has-line-data" data-line-start="54" data-line-end="55">int m_rating; };</p>
<p class="has-line-data" data-line-start="56" data-line-end="57">// Remove the movies in li with a rating below 50 and destroy them.</p>
<p class="has-line-data" data-line-start="58" data-line-end="59">// It is acceptable if the order of the remaining movies is not // the same as in the original list. void removeBad(list&lt;Movie*&gt;&amp; li) { }</p>
<p class="has-line-data" data-line-start="60" data-line-end="61">void test() {</p>
<p class="has-line-data" data-line-start="62" data-line-end="63">int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 }; list&lt;Movie*&gt; x; for (int k = 0; k &lt; 8; k++)</p>
<p class="has-line-data" data-line-start="64" data-line-end="65">x.push_back(new Movie(a[k])); assert(x.size() == 8 &amp;&amp; x.front()-&gt;rating() == 85 &amp;&amp; x.back()-&gt;rating() == 10);</p>
<p class="has-line-data" data-line-start="66" data-line-end="67">removeBad(x); assert(x.size() == 4 &amp;&amp; destroyedOnes.size() == 4); vector&lt;int&gt; v; for (list&lt;Movie*&gt;::iterator p = x.begin(); p != x.end(); p++) {</p>
<p class="has-line-data" data-line-start="68" data-line-end="69">Movie* mp = *p; v.push_back(mp-&gt;rating()); } sort(v.begin(), v.end()); int expect[4] = { 70, 80, 85, 90 }; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="70" data-line-end="71">assert(v[k] == expect[k]); sort(destroyedOnes.begin(), destroyedOnes.end()); int expectGone[4] = { 10, 15, 20, 30 }; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="72" data-line-end="73">assert(destroyedOnes[k] == expectGone[k]); }</p>
<p class="has-line-data" data-line-start="74" data-line-end="75">int main() {</p>
<p class="has-line-data" data-line-start="76" data-line-end="77">test(); cout &lt;&lt; “Passed” &lt;&lt; endl; return 0; }</p>
<p class="has-line-data" data-line-start="78" data-line-end="79">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="80" data-line-end="81">d. Implement the removeBad function: #include &lt;vector&gt; #include &lt;algorithm&gt; #include &lt;iostream&gt; #include &lt;cassert&gt; using namespace std;</p>
<p class="has-line-data" data-line-start="82" data-line-end="83">vector&lt;int&gt; destroyedOnes;</p>
<p class="has-line-data" data-line-start="84" data-line-end="85">class Movie {</p>
<p class="has-line-data" data-line-start="86" data-line-end="87">public:</p>
<p class="has-line-data" data-line-start="88" data-line-end="89">Movie(int r) : m_rating® {} ~Movie() { destroyedOnes.push_back(m_rating); } int rating() const { return m_rating; } private:</p>
<p class="has-line-data" data-line-start="90" data-line-end="91">int m_rating; };</p>
<p class="has-line-data" data-line-start="92" data-line-end="93">// Remove the movies in v with a rating below 50 and destroy them.</p>
<p class="has-line-data" data-line-start="94" data-line-end="95">// It is acceptable if the order of the remaining movies is not // the same as in the original vector. void removeBad(vector&lt;Movie*&gt;&amp; v) { }</p>
<p class="has-line-data" data-line-start="96" data-line-end="97">void test() {</p>
<p class="has-line-data" data-line-start="98" data-line-end="99">int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 }; vector&lt;Movie*&gt; x; for (int k = 0; k &lt; 8; k++)</p>
<p class="has-line-data" data-line-start="100" data-line-end="101">x.push_back(new Movie(a[k])); assert(x.size() == 8 &amp;&amp; x.front()-&gt;rating() == 85 &amp;&amp; x.back()-&gt;rating() == 10);</p>
<p class="has-line-data" data-line-start="102" data-line-end="103">removeBad(x); assert(x.size() == 4 &amp;&amp; destroyedOnes.size() == 4); vector&lt;int&gt; v; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="104" data-line-end="105">v.push_back(x[k]-&gt;rating()); sort(v.begin(), v.end()); int expect[4] = { 70, 80, 85, 90 }; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="106" data-line-end="107">assert(v[k] == expect[k]); sort(destroyedOnes.begin(), destroyedOnes.end()); int expectGone[4] = { 10, 15, 20, 30 }; for (int k = 0; k &lt; 4; k++)</p>
<p class="has-line-data" data-line-start="108" data-line-end="109">assert(destroyedOnes[k] == expectGone[k]); }</p>
<p class="has-line-data" data-line-start="110" data-line-end="111">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="112" data-line-end="113">int main() {</p>
<p class="has-line-data" data-line-start="114" data-line-end="115">test(); cout &lt;&lt; “Passed” &lt;&lt; endl; return 0; }</p>
<ol start="2">
<li class="has-line-data" data-line-start="116" data-line-end="118">Some word games, like Scrabble, require rearranging a combination of letters to</li>
</ol>
<p class="has-line-data" data-line-start="118" data-line-end="119">make a word. This type of arrangement is generally referred to as an anagram, it’s known as a permutation in mathematics. Write a C++ program that searches for anagrams in a dictionary. An anagram is a word obtained by scrambling the letters of some string. For example, the word “pot” is an anagram of the string “otp”. A sample run of the program is given below. Your output does not have to be formatted exactly the same as that shown in the sample, but should be in a similar style. You can use words.txt as your dictionary file.</p>
<p class="has-line-data" data-line-start="120" data-line-end="121">Sample Runs</p>
<p class="has-line-data" data-line-start="122" data-line-end="123">Here are two examples of how the program might work:</p>
<p class="has-line-data" data-line-start="124" data-line-end="125">Please enter a string for an anagram: opt Matching word opt Matching word pot Matching word top</p>
<p class="has-line-data" data-line-start="126" data-line-end="127">Please enter a string for an anagram: blah No matches found</p>
<p class="has-line-data" data-line-start="128" data-line-end="129">Requirements</p>
<p class="has-line-data" data-line-start="130" data-line-end="131">You must write these three functions with the exact same function signature (include case):</p>
<p class="has-line-data" data-line-start="132" data-line-end="133">int loadDictionary(istream &amp;dictfile, vector&lt;string&gt;&amp; dict);</p>
<p class="has-line-data" data-line-start="134" data-line-end="135">Places each string in dictfile into the vector dict. Returns the number of words loaded into dict.</p>
<p class="has-line-data" data-line-start="136" data-line-end="137">int permute(string word, vector&lt;string&gt;&amp; dict, vector&lt;string&gt;&amp; results);</p>
<p class="has-line-data" data-line-start="138" data-line-end="139">Places all the permutations of word, which are found in dict into results. Returns the number of matched words found.</p>
<p class="has-line-data" data-line-start="140" data-line-end="141">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="142" data-line-end="143">void display(vector&lt;string&gt;&amp; results);</p>
<p class="has-line-data" data-line-start="144" data-line-end="145">Displays size number of strings from results. The results can be printed in any order.</p>
<p class="has-line-data" data-line-start="146" data-line-end="147">For words with double letters you may find that different permutations match the same word in the dictionary. For example, if you find all the permutations of the string kloo using the algorithm we’ve discussed you may find that the word look is found twice. The o’s in kloo take turns in front. Your program should ensure that matches are unique, in other words, the results array returned from the permute function should have no duplicates.</p>
<ol start="3">
<li class="has-line-data" data-line-start="148" data-line-end="150">Imagine you are working for a small hedge fund, and your mission is to catch</li>
</ol>
<p class="has-line-data" data-line-start="150" data-line-end="151">inside traders. You have a new pattern that you think might indicate to you that something suspicious like inside trading may be occurring: The profile made, or loss prevented, by an INIDIVIDUAL trade due to changes in the price of that stock within a 3 day window after the trade was made is greater than or equal to $500,000. You want to build an algorithm that is capable of taking the hedge fund’s data as input and generating a list of occurrences of this pattern.</p>
<p class="has-line-data" data-line-start="152" data-line-end="153">For a given stock ticker, you have a pipe-delimited data source sorted by day with two primary pieces of information: the price of said stock on each day and the trades of that stock made by each trader at the hedge fund over time. More specifically, you receive this data as a String Array where each element in the array is one of:</p>
<p class="has-line-data" data-line-start="154" data-line-end="155">• Stock Price - the value of the stock on a given day</p>
<p class="has-line-data" data-line-start="156" data-line-end="157">o These elements are simply &lt;DAY&gt;|&lt;PRICE&gt;, where DAY is the integer number of days since the fund has opened and price is integer dollar amount value of the stock on that day. o Price is only recorded when it has changed from the day before, and will</p>
<p class="has-line-data" data-line-start="158" data-line-end="159">always have an entry for day 0</p>
<p class="has-line-data" data-line-start="160" data-line-end="161">• Trade - the trade made by a specific trader for a stock on a given day</p>
<p class="has-line-data" data-line-start="162" data-line-end="163">o These elements are of the format</p>
<p class="has-line-data" data-line-start="164" data-line-end="165">&lt;DAY&gt;|&lt;TRADER&gt;|&lt;TRADE_TYPE&gt;|&lt;AMOUNT&gt;, where trader TRADER either bought or sold depending on the value of TRADE_TYPE and integer AMOUNT number of that stock on the specified day. o TRADE_TYPE will either be “BUY” or “SELL”</p>
<p class="has-line-data" data-line-start="166" data-line-end="167">Your output is another String Array that can be fed into other systems at the hedge fund and is simply an entry of the format &lt;DAY&gt;|&lt;TRADER&gt; where DAY is the day said TRADER made the trade that triggered the alert, not the day that</p>
<p class="has-line-data" data-line-start="168" data-line-end="169">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="170" data-line-end="171">the stock price changed. This output should be sorted by day and then trader name, and should not include duplicates.</p>
<p class="has-line-data" data-line-start="172" data-line-end="173">Example Explanation</p>
<p class="has-line-data" data-line-start="174" data-line-end="175">In this example, “1|Tom” is considered a suspicious trade because:</p>
<p class="has-line-data" data-line-start="176" data-line-end="177">• On day 0 the stock price gets set at $20 - “0|20”</p>
<p class="has-line-data" data-line-start="178" data-line-end="179">• On day 1 Tom buys 150,000 stock “1|Tom|BUY|150000”</p>
<p class="has-line-data" data-line-start="180" data-line-end="181">• On day 3, 2 days later (i.e. within 3 days), the stock price increases from $20 to $25 - “3|25”</p>
<p class="has-line-data" data-line-start="182" data-line-end="183">o This represents a 25 - 20 = $5 difference in stock price o Tom’s trade on day 1 therefore earned him a profit of $5 * 150,000 =</p>
<p class="has-line-data" data-line-start="184" data-line-end="185">$750,000, which is over our threshold</p>
<p class="has-line-data" data-line-start="186" data-line-end="187">Also “8|Kristi” is a suspicious trader because:</p>
<p class="has-line-data" data-line-start="188" data-line-end="189">• On day 3 the stock price gets set at $25 - “3|25”</p>
<p class="has-line-data" data-line-start="190" data-line-end="191">• On day 8 Kristi sells 60,000 stock “8|Kristi|SELL|60000”</p>
<p class="has-line-data" data-line-start="192" data-line-end="193">• On day 10, 2 days later (i.e. within 3 days), the stock price decreases from $25 to $15 - “10|15”</p>
<p class="has-line-data" data-line-start="194" data-line-end="195">o This represents a 15 - 25 = $-10 difference in stock price o Kristi’s trade on day 8 therefore prevented a loss of $10 * 60,000 =</p>
<p class="has-line-data" data-line-start="196" data-line-end="197">$600,000, which is over our threshold o Note that on day 11 (also within 3 days) the stock price decreases again</p>
<p class="has-line-data" data-line-start="198" data-line-end="199">from $15 to $5 = “11|5” o Compared to day 8, this represents a 5 - 25 = -$20 difference in stock</p>
<p class="has-line-data" data-line-start="200" data-line-end="201">price since Kristi’s purchase, which amounts to preventing a loss of $1.2 million o However, Kristi’s trade on day 8 was already flagged, so we should not</p>
<p class="has-line-data" data-line-start="202" data-line-end="203">add it to our results set because we do not want duplicates</p>
<p class="has-line-data" data-line-start="204" data-line-end="205">Similarly, Will is not considered to have a suspicious trade:</p>
<p class="has-line-data" data-line-start="206" data-line-end="207">• The price of stock on day 11 is $5 - “11|5”</p>
<p class="has-line-data" data-line-start="208" data-line-end="209">• He buys 30 thousand total stock between days 14 and 16, inclusive - [ “14|Will|BUY|10000”, “15|Will|BUY|10000”, “16|Will|BUY|10000” ]</p>
<p class="has-line-data" data-line-start="210" data-line-end="211">• The price of the stock on day 17 increases to $25</p>
<p class="has-line-data" data-line-start="212" data-line-end="213">o This represents a $20 difference o Will has profited $20 * 30,000 = $600,000 TOTAL o The amount of profit earned by any one of his 3 individual trades is only</p>
<p class="has-line-data" data-line-start="214" data-line-end="215">$20 * 10,000 = $200,000 o $200,000 is less than the threshold amount of $500,000 for any</p>
<p class="has-line-data" data-line-start="216" data-line-end="217">INDIVIDUAL trade and thus is not flagged.</p>
<p class="has-line-data" data-line-start="218" data-line-end="219">CS 30 – Fall 2019 E. Ambrosio</p>
<p class="has-line-data" data-line-start="220" data-line-end="221">Turn It In</p>
<p class="has-line-data" data-line-start="222" data-line-end="223">You will submit this homework via Canvas. Turn in one zip file that contains your solutions to the homework problem. The zip file must these three files:</p>
<p class="has-line-data" data-line-start="224" data-line-end="225">• removeBad.cpp, this will have the functions from part 1. Put the four functions in one file.</p>
<p class="has-line-data" data-line-start="226" data-line-end="227">• anagram.cpp, this will have the solution to part 2.</p>
<p class="has-line-data" data-line-start="228" data-line-end="229">• trader.cpp, this will have the solution to part 3.</p>
