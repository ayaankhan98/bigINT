#include <bigint.hpp>
#include <iostream>
#include <cassert>

int main() 
{
    /// Tests for multiplication of largeInt to largeInt (largeInt * largeInt)
    /// Test 1
    libbig::largeInt a("1");
    libbig::largeInt b("1");
    libbig::largeInt c = a * b;
    assert(c == libbig::largeInt("1"));

    /// Test 2
    a = libbig::largeInt("999");
    b = libbig::largeInt("99999");
    c = a * b;
    assert(c == libbig::largeInt("99899001"));

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

    return 0;
}