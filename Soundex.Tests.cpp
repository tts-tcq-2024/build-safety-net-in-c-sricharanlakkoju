#include <gtest/gtest.h>
#include "Soundex.h"
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//AAA
  char soundex[5];
generateSoundex("$rrr", soundex);
ASSERT_STREQ(soundex,"$666");
}
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
//AAA
char soundex[5];
generateSoundex(" ", soundex);
ASSERT_STREQ(soundex," 000");
}
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
//AAA
  char soundex[5];
generateSoundex("*#12hi", soundex);
ASSERT_STREQ(soundex,"*000");
}
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_vowels) {
//AAA
char soundex[5];
generateSoundex("aeiou", soundex);
ASSERT_STREQ(soundex,"A000");
}
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_space) {
//AAA
char soundex[5];
generateSoundex(" ", soundex);
ASSERT_STREQ(soundex," 000");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
//AAA
char soundex[5];
generateSoundex("bcdlmnr", soundex);
ASSERT_STREQ(soundex,"B234");
}
