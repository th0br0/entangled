/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * Refer to the LICENSE file for licensing information
 */

#include <cstdint>
#include <iostream>
#include <memory>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "common/helpers/digest.h"
#include "common/helpers/pow.h"

namespace {
const std::string TX_TRYTES =
    "XYIUIABLAEBBFCTMDCGPVNCQELHIEBVNRPWBSCABWRAVGVOVMFEHWJCUILYIXOPJNASEOHXP"
    "JBXFNHHSWEKEGEEFSAZDENWMOAXGJCQZQDGSTTMNQPYJBLRVY9T9HSQNXWYCSMLEXVWCASQ9"
    "MHPMBZ9PSSZEKCXYLDYKTOVAWQXOTGMWHUIACLUTAIKUIXZND9YMQKZBTIWOUIVQWTSBNVDC"
    "UWYP9HDMQPTXWEQYXVEOFXVGQSBHGHMKVFZZQIALVLMINZGNLEAOCQZFHPTQTQXGZQJLTBFP"
    "LWTESFYOJNJGJRYWHPEBSPSXEWCITXBJBMXDFCUDUKKGZMDOOPIBJLC9GPIBTLVQWPGTADEX"
    "NI9SWJNJXKXIJCPMICHBIFRXVWNJDP9BDELH9NOMJKGEBOCLWEXPEBFBWQLHFWQVCFIPVUXN"
    "REWXTCTFQHZYTMSUXQZTJQOWZZZCFIJ9NFXVSDFEXLODNJFREDOQ9WLLQAKRYKUCGUYEFICO"
    "LCKZHWFCLFGLKORFQFZXZXTEXWGRJPZ99KAJYFDWZNMBKQXOLRCAPDZWTZIMSUDSNDTKJLKJ"
    "WFCTHZFYFW9EF9T9OGNFBNCRDDTRQUBIBSIWJNRAFXG9UDRGSXDQ9OKAREHQOCXSULYOA9IW"
    "JOYGWYOZGVQUDNBZXHZBCCBQ9PPKIKSWLNLPRSRRYLGCQIJKYNTAJBGPAOYWIUOIR9WOQYLS"
    "QYPWKUWBD9AUVZZT9KWUNQZYLOKTWRVJDVJSDBO9XYEGJIZWRMU9SRUVGMZUX9BXACUDYNXX"
    "RTYN9UVLJUIJGNAHVWSWRFHKIXTYINVHFHGXJVVJFLFTJR9LPZCJPHQOZQRXFJPYIHCVBXCI"
    "XZFPCC9RYLOYMBXDTRDEDWPZMZYIKGTXAQYJVEFDSF9QWROXAJS9ZPAWHLKIEKUPFKXOGLUY"
    "XCQNVVBYEJG9STYYRHKAOOID9UDPCMSBOVKWXCTSRSBKOZIIUDAABKXIBIDNTXZWLITYANTG"
    "VRYBEOZAOEWGPGLKGICMPADAEHHOCUSKXBKO9REVSI9FDFDCPMUGCLJVNHMHWHAIURTWDTSH"
    "MOPVVMGWLECCPXHAAQRCDCUWDVMBRLMQYTY9PLIFIUNXZUNY9UIVHBZKMNYOPRSIKBKWDDOY"
    "JQWCSPFBLODZVAPGWHJJKOBYETEUUPJDIFLWUCMYWEUSZLWANGHYSNUXJAPFZJADQWAZCOYX"
    "WJAQCYWFBRNXJRHMIUFEROW9Z9QJAPFDIRUUTD9RPZYFD9PRPU9YVGIQMHNEYVDLEIESZEO9"
    "QLOLNHSVNGNZFHODQXXX9K9NAUDG9UENCXFTS9FQXVXJYIVBL9OPHXTPCWKEDMXXJQLXHBNT"
    "NVWHGFNNXAEKGHSBGCQFFIIRKMSYRXBCDTUCJESVXJGZTHUJWGWDD9MDXBCXEPBMDZEVUGIX"
    "HVCGDFVOYY9QEJJYQALKJWFKMYSKZRXQNGI9MC9FLSIYER9BZGDXGZUAMBZFJLWNBKMWWOSU"
    "E9XGOUPDDSCJWN9PJD9LKUVVYHCRBBBABVKZJOXFGCRXXDEGLGYDXLFFPWFNCGCRPKGSEXQN"
    "ONXKJWDGTFZWWOSK9TKUTHGHBNLQADQ9QS9XLNRVUMSRFVYVSEQEGGTOWHUMZUEVQEROFMYL"
    "XYXU9GUJSQFSMMVHQS9SVIH9X9RNORYZOLIIA9RWAUFWDKQXRAHPALEW9LDXZFSRDCPYVSSX"
    "GOEPSVZCVWXDXVJKDWUBGQEUGNAUD9GNEQEVXXLTNVBIWJLLBCTFZWODFLIIDSNUPDJRHNPH"
    "9NBOKOVXCGEEZA9ZWKRNBL9XOOPF9OCP9VORMMVSIASCEAUVVJHBLWLHDHWVJDDTEBFIKHOE"
    "VIIDJXA9MTLUSZVPJPHLRASOAGNNPQYIAZVKTROQXISIALDESIHLNREAAPXCFU9AZTORQGYC"
    "FWVFHFQMAJPUSYVAEERWGQSKYFZJPWMOAEWXTUEGIDOSSCLBFLMBIZHYIQWSCNPZUTTSKCZX"
    "DSELK9KSBHTDSUID9LMBMYXQFAWBBRHFKMMBPTFKDNLQSZAMHMYASZXXKHXKPH9TOHVZUOXD"
    "CFHBDNAQEVOQQUGKEW9YQBZWMSVTJGNVUN9TUVYJ9XECFMVIIFTNSNBCUA9TOHPHAYDSAWJT"
    "JANNPZELFSWMVLBRUKJDT9B9VWCXBMUDNLVDEEWQRITLOTFLVOUDQGEEXK9CO9DCMNDY9VZU"
    "GMLVFKLUBNSQOABRDMIWVYGMENSBHUOMGIJ9MNKLST999999999999999999999999999999"
    "999999999999999999UMJOPYD99A99999999C99999999WUIHHDPDFBHIQLKEFLUOKIOVFOC"
    "PFPWBKUCCGA9YUUEPTLUXRLZHVKEOLJQWHBOLSCWKVXCOBSVJHY9YXDMTFSSWIPNAYXJPQNQ"
    "CZAIT9ADYOLDXZVBTEUWMVYOOODSCPKAWWHOFQTLZKRPURYBMCU9YHSIYQZ9999W9VELHQPP"
    "ERYSG9ZLLAHQKDLJQBKYYZOSRQOESEELED9CZHBLAMALTJJZAFWNMWGAAUFJMNQDGKVA9999"
    "999999999999999999999999999HDU9RGVJE999999999MMMMMMMMM999999999999999999"
    "999999999";

TEST(PoWTest, testsPoW) {
  using namespace testing;

  auto nonce = iota_pow_trytes(TX_TRYTES.c_str(), 9);
  auto powed = TX_TRYTES.substr(
                   0, NUM_TRYTES_SERIALIZED_TRANSACTION - NUM_TRYTES_NONCE) +
               nonce;

  auto c_hash = iota_digest(powed.c_str());
  auto hash = std::string(c_hash);

  EXPECT_EQ("999", hash.substr(NUM_TRYTES_HASH - 3));

  std::free(nonce);
  std::free(c_hash);
}

TEST(PoWTest, testsFlexPoW) {
  using namespace testing;

  flex_trit_t tx[FLEX_TRIT_SIZE_8019] = {0};
  flex_trits_from_trytes(tx, NUM_TRITS_SERIALIZED_TRANSACTION,
                         (const tryte_t *)TX_TRYTES.c_str(), TX_TRYTES.length(),
                         TX_TRYTES.size());

  auto nonce = iota_pow_flex(tx, FLEX_TRIT_SIZE_8019, 9);

  flex_trits_insert_from_pos(
      tx, NUM_TRITS_SERIALIZED_TRANSACTION, nonce, NUM_TRITS_NONCE,
      NUM_TRITS_SERIALIZED_TRANSACTION - NUM_TRITS_NONCE, 0, NUM_TRITS_NONCE);
  auto c_fhash = iota_flex_digest(tx, FLEX_TRIT_SIZE_8019);

  tryte_t c_hash[81] = {0};
  flex_trits_to_trytes(c_hash, NUM_TRITS_HASH, c_fhash, NUM_TRITS_HASH,
                       NUM_TRITS_HASH);

  auto hash = std::string((const char *)c_hash, 81);

  std::cerr << hash << std::endl;

  std::free(nonce);
  std::free(c_fhash);

  EXPECT_EQ("999", hash.substr(NUM_TRYTES_HASH - 3));
}

}  // namespace
