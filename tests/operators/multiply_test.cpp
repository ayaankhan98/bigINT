#include <bigint.hpp>
#include <iostream>
#include <cassert>

int main() 
{
    /// Tests for multiplication of largeInt to largeInt (largeInt * largeInt)
    /// Test 1
    libbig::largeInt a("1111");
    libbig::largeInt b("1");
    libbig::largeInt c = a * b;
    assert(c == libbig::largeInt("1111"));

    /// Test 2
    a = libbig::largeInt("24");
    b = libbig::largeInt("25");
    c = a * b;
    assert(c == libbig::largeInt("600"));

    /// Test 3
    a = libbig::largeInt("32516889472103571029388908423975");
    b = libbig::largeInt("0");
    c = a * b;
    assert(c == libbig::largeInt("0"));

    /// Test 4
    a = libbig::largeInt("6666666666666");
    b = libbig::largeInt("58723619378");
    c = a * b;
    assert(c == libbig::largeInt("391490795853294184253748"));

    // Test 5
    a = libbig::largeInt("33");
    b = libbig::largeInt("-2");
    c = a * b;
    assert(c == libbig::largeInt("-66"));

    // Test 6
    a = libbig::largeInt("78239823648904375");
    b = libbig::largeInt("1273898653482713986555");
    c = a * b;
    assert(c == libbig::largeInt("99669605995064285419229672514230678125"));

    // Test 7
    a = libbig::largeInt("-0");
    b = libbig::largeInt("100");
    c = a * b;
    assert(c == libbig::largeInt("0"));

    // Test 8
    a = libbig::largeInt("-100");
    b = libbig::largeInt("-100");
    c = a * b;
    assert(c == libbig::largeInt("10000"));

    // Test 9
    a = libbig::largeInt("0000000000000000000000000000000000000000000000000000");
    b = libbig::largeInt("1111111111111111111111111111111111111111111111111111");
    c = a * b;
    assert(c == libbig::largeInt("0"));

    // Test 10
    a = libbig::largeInt("746767836578647567834567834657836587");
    b = libbig::largeInt("89275924758922476024759846938475804579247593468034769835763597028476937");
    c = a * b;
    assert(c == libbig::largeInt("66668389190778655840704160824409791548824154145813767587653936294222881640592188804856387839101068044294019"));

    // Test 10
    a = libbig::largeInt("8492387957349593498354782359782345782367895623478567894235692347856789234789236789342967891235627348589234567892345234567892369287345");
    b = libbig::largeInt("824358293475908745902350926589023459023485089347892650234650273456207349236502347524357832456789235623489759235623789456782394567892359478235239423569782356234659837562378965278956237489235");
    c = a * b;
    assert(c == libbig::largeInt("7000770444056069403046119404826740387252166452093943636486324185225836788920060077258109995450330997820727632474615791121779806923541276193853962113432983583426568371447855101334504301369704676060587738461922443343618487980096828486083202559107333726983966552151422667448209619250487990929538296732965889159956209059231075"));

    /// Tests for multiplication of largeInt to largeInt (largeInt * int)
    /// Test 1
    a = libbig::largeInt("1");
    int d { 1 };
    c = a * d;
    assert(c == libbig::largeInt("1"));

    /// Test 2
    a = libbig::largeInt("999");
    d = 99999;
    c = a * d;
    assert(c == libbig::largeInt("99899001"));

    /// Test 3
    a = libbig::largeInt("32516889472103571029388908423975");
    d = 0;
    c = a * d;
    assert(c == libbig::largeInt("0"));

    /// Test 4
    a = libbig::largeInt("6666666666666");
    d = 2147000000;
    c = a * d;
    assert(c == libbig::largeInt("14313333333331902000000"));

    // Test 5
    a = libbig::largeInt("33");
    d = -2;
    c = a * d;
    assert(c == libbig::largeInt("-66"));

    // Test 6
    a = libbig::largeInt("-0");
    d = 100;
    c = a * d;
    assert(c == libbig::largeInt("0"));

    // Test 7
    a = libbig::largeInt("-100");
    d = -100;
    c = a * d;
    assert(c == libbig::largeInt("10000"));

    // Test 8
    a = libbig::largeInt("0000000000000000000000000000000000000000000000000000");
    d = 1111111111;
    c = a * d;
    assert(c == libbig::largeInt("0"));

    // Test 9
    a = libbig::largeInt("824358293475908745902350926589023459023485089347892650234650273456207349236502347524357832456789235623489759235623789456782394567892359478235239423569782356234659837562378965278956237489235");
    d = 2147111111;
    c = a * d;
    assert(c == libbig::largeInt("1769988851367122479149013395500437599508978045281688053754054359337011171465551557147132045207848595192391874649522705358582133685907728887725045238091914980923198260535639031943130151995891211390085"));

    // Test 10
    a = libbig::largeInt("824358293475908745902350926589023459023485089347892650234650273456207349236502347524357832456789235623489759235623789456782394567892359478235239423569782356234659837562378965278956237489235");
    d = -0;
    c = a * d;
    assert(c == libbig::largeInt("0"));

    /// Tests for multiplication of largeInt to largeInt (largeInt * int64_t(long long))
    /// Test 1
    a = libbig::largeInt("1");
    int64_t e { 1 };
    c = a * e;
    assert(c == libbig::largeInt("1"));

    /// Test 2
    a = libbig::largeInt("999");
    e = 99999;
    c = a * e;
    assert(c == libbig::largeInt("99899001"));

    /// Test 3
    a = libbig::largeInt("32516889472103571029388908423975");
    e = 0;
    c = a * e;
    assert(c == libbig::largeInt("0"));

    /// Test 4
    a = libbig::largeInt("6666666666666");
    e = 2147000000;
    c = a * e;
    assert(c == libbig::largeInt("14313333333331902000000"));

    // Test 5
    a = libbig::largeInt("33");
    e = -2;
    c = a * e;
    assert(c == libbig::largeInt("-66"));

    // Test 6
    a = libbig::largeInt("-0");
    e = 100;
    c = a * e;
    assert(c == libbig::largeInt("0"));

    // Test 7
    a = libbig::largeInt("-100");
    e = -100;
    c = a * e;
    assert(c == libbig::largeInt("10000"));

    // Test 8
    a = libbig::largeInt("0000000000000000000000000000000000000000000000000000");
    e = 1111111111;
    c = a * e;
    assert(c == libbig::largeInt("0"));

    // Test 9
    a = libbig::largeInt("824358293475908745902350926589023459023485089347892650234650273456207349236502347524357832456789235623489759235623789456782394567892359478235239423569782356234659837562378965278956237489235");
    e = 2147111111;
    c = a * e;
    assert(c == libbig::largeInt("1769988851367122479149013395500437599508978045281688053754054359337011171465551557147132045207848595192391874649522705358582133685907728887725045238091914980923198260535639031943130151995891211390085"));

    // Test 10
    a = libbig::largeInt("824358293475908745902350926589023459023485089347892650234650273456207349236502347524357832456789235623489759235623789456782394567892359478235239423569782356234659837562378965278956237489235");
    e = -0;
    c = a * e;
    assert(c == libbig::largeInt("0"));

    // Test 1
    a = libbig::largeInt("824358293475908745902350926589023459023485089347892650234650273456207349236502347524357832456789235623489759235623789456782394567892359478235239423569782356234659837562378965278956237489235");
    e = 1265387145178649877;
    c = a * e;
    assert(c == libbig::largeInt("1043132387585823801991307287703268230197717355664659943770242721775843792669363443147242163866322648004732006134963833033002779153256893032797217422608922304113441680757314641399751543910917847399909621574095"));

    return 0;
}