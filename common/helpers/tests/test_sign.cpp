#include <cstdint>
#include <iostream>
#include <memory>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "common/helpers/sign.h"

namespace {

TEST(KerlTest, testAddressGeneration) {
  using namespace testing;

  const std::string SEED =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ9ABCDEFGHIJKLMNOPQRSTUVWXYZ9ABCDEFGHIJKLMNOPQ"
      "RSTUVWXYZ9";

  const std::string EX_ADD_0_1 =
      "CFOYUCXLHLSUBAEYOTAWUNRPJFA9TSJNLBFLMZQASPTVCMTFBOQQRGGQ9MRZCJWYGBORJZQW"
      "VSBLVKBVW";
  const std::string EX_ADD_2_2 =
      "TZZUOMKXUUIIAJEQJJRIJQKWQVYK9YPFNWWUUHDQWVVWIBWHC9J9FJJEFZKOZZAIMUDDGHOI"
      "WTIWCOHGD";
  const std::string EX_ADD_2_3 =
      "MLAUELWJHZ9QBPCIYLOXAWCVSZTK9XUEIWQSRLFDWEORDOLVOMOF9RUMFXSAMYWCGXDAVXZM"
      "RWQOJH9RY";

  char* out_1 = iota_sign_address_gen(SEED.c_str(), 0, 1);
  char* out_2 = iota_sign_address_gen(SEED.c_str(), 2, 2);
  char* out_3 = iota_sign_address_gen(SEED.c_str(), 2, 3);

  EXPECT_EQ(out_1, EX_ADD_0_1);
  EXPECT_EQ(out_2, EX_ADD_2_2);
  EXPECT_EQ(out_3, EX_ADD_2_3);

  free(out_1);
  free(out_2);
  free(out_3);
}

TEST(KerlTest, testSignature) {
  const std::string SEED =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ9ABCDEFGHIJKLMNOPQRSTUVWXYZ9ABCDEFGHIJKLMNOPQ"
      "RSTUVWXYZ9";

  const std::string EX =
      "IRRWWESEWUSGFCQZQUETVGNLONDOHXJRQPECGNOI9FSDSVDHH9EXGXHLW9TXQSFRZK9TKFMW"
      "SLOGAD9OWUCQCZTCRHQXINFJHVGPVWYWFKIGHUAYFWNJXGZZYISMFTVQKDLUQWHEVUWYCIHE"
      "VW9QKRJSYDCBTFTOL9HTNPRBPGTSQACDUGZSXRJWSKFJUXCH9TEXJUUDOI9EDDFAQ9QMDNPJ"
      "DZLZPUMVGBOUNFYHKWSICCGEKLZHECPB9SKR9NW9NUUCIGYJZZHQGAWMA9PFQOQMBFOYXWYZ"
      "SZRAENTWFOHTYWZCM9NYFBKQGKL9APFFZ9YDMUASLWRMQHJETMUAEY99WGDOUDBSHMPQAPKG"
      "9LQHAJMMIEUAX9OQHQKMMNFA9GUDQENAELLL99CZLTRFYNGXUREWFUHIKQJVHCSTOWZIOCJV"
      "DE9ZRC9PMJEOUMNRILRBE9KDLKHDRQHIWEDLHVDEHZPOFXYGHHAMACOPNRV9EZBSFYITYURV"
      "QSJOZWESIYRMHOYZHEEHMTAYPNMIJMPUF9OSCEWPQEKWOHSOMLPZJUIXWVJMLMDUWCCWGPVK"
      "BUUUEGAKJYSYAWWDWY9RZITWOHZTMTXPLHTDFTZJDLBJFFJ9RHXZBBHOIHV9UFRYRAABMKEA"
      "UUOOIGCWVNOKKPUODIQJYSFTUAKIBNJ9YIYVCNMUDGHLQENMWSDUHGZIA9FYIPOSFEOLDCRY"
      "SXRCJSJOCNIE9GLCRMXQFAUERKRDEAGVVPSSEUFWFFYEYRWAHHZPNQWQYHWCTJXBGSJKBGZG"
      "PQZJOVLRFQZGLJURVCSIXOGDPZPIVHDCTOBDEYTVUFILZ9PMBAQNOWHPNBLXYYJSMZKRBACR"
      "VPGKXUQSEA9NTHUFUHTP9OYBIIDFJIUGNTNCHVHX99MQ9IAMRNJNZL9KGQ9VKYNXMANFDHAB"
      "PSYDQLBMTVDOKFFZQZPABWUTLVDKUYKBZNDDM9HZKK9ZL9BHKWGKILNTZGHCWSNKQBITFFRB"
      "CZTRNJAHGCZBJVGRYNYYBDYXNWCENEOXDDZODTGMI9LGDVCZWALMADQJHOEHQLYBSRXUSGBB"
      "MFENSDX9NVFHHIJAEPRDDNRCN9DMTLOOUASJLXNXLJN9VKEVRLRIMZOYNHGHVERWERXP9NIM"
      "MFVZMVWCPAOBZDPKOSNXYK9CZFPUINBREOYJBVBASSWWKKDQGQBBAYPSQCZDFSZZIYJFVMFV"
      "HGE9HJZTLB9POVGTBGZCTMBLNXGHZCDUKWAPPTGXKSXSAUKICBRCKYK9KTSNFKEJKJE9UHTC"
      "KPNUWRHKSYQRSHIVGRBTRBWEQ9KS9LNTLRUWRLWTVYNLVVMNXPNZPYMATERXEVVTSBRCNYPA"
      "9DXNLQXP9RLVAKDAGOJDDOMAXODLLZEHHRFSDDNMPMKOP9YCBDDBTYUYOHCJYQHLKSECHQUW"
      "ZZRPEYGFSIMMO9JDXDEXUETJIEBJMBTRGFTWXPQZXAWDFNQGPUDQESGAAN9WNFNTDIAZ9DKW"
      "JKPOKZESUYMVC9AEVNCTAWZLZB9GUSUWASJTVIJBCKUZLBSBVCUBAAPDTADOSERGKMDLBUGV"
      "OHNMPGCLYIPFVECMYXJBFPWWJUVQTJSOY9OWZGYOYZYAUWFRBPRRXMPDQIFLFYEJURGSFT9N"
      "OINQF9DSHSNGJKHOUEPPBGOMENJNVFZHHMGOABXTMF9DANGGQGKDCSXZNEOPEMIDOULWF9BH"
      "N9UCOZDFOYZ9AHDCEANXWVHNJMOMLVS9YYDHTNEFDPCVKDTCIMHDADUVRKCDNGPWVCJBZOPW"
      "9EU9YXOWTVBWHCYCVUIVRGXXIDFWZCDTTTBHWYH9VNT9CEYOEECS9AXYKBCSIHCABBGJYTSK"
      "FJJADIMQBZNZLZPIIZDCJDVIWZXGKSQDDMSXCJEWGWAUJXIO9FTHLYXRKQWDKZ9X9HRIKDQX"
      "PJSWKNM9S9KWRGTIEHFPVFFYZXRAWSKKXDLBRTTYAXRIKHESEOXCURUPJLXWWIIGDMBUIBRF"
      "CLLICDZXDDPSDP9NSZYBIYEZSVIQLQCXZJLHXUJJGPHRDILDMLDSVKXI9LZWZDPIVFABZTVF"
      "SNFLUHDBPFMCKNFSTXMTQHGSGXXSRWCRDKBHZGQVEPPRSIHKZSGCZOKJTUNHRDOLNZVXARQX"
      "DUZMZZ9AGLOKYBKYRQMDJKQJOIA"
      "JXXHYSPUJEL9PSLRGUMNCUZRNDLIUXYVJWGUIFOWVWGFNVVRPWIGS9POUUFBLFH9VYRTOSVL"
      "IXJSYOCEXSNRAYWBWYGJRYJGZRZGK9DCSJ9LFZZMNCLQKBMGYJOL9NWEZURYXHEMMEWZPN9S"
      "VKRKQVUFGWWRRC9VGA9JVXALSWYDFKYCJQTJAPRACLEUYQSCFHYOUUGMWXZOLOPBA9UGZGDL"
      "B9ZKHSYPXLBRVONMZWZZLHQYSNCVDCJXUTVUKAYDAQYYHDMEZVCFASPTGJPVZCZCUKAOVTJC"
      "OAIMISYURFVXWNCKSWNHNZWOPUQFTJAFRRFWDHQECFSSOIFICV9GYMCHOBSXFZSCLQMJZJJQ"
      "YLDYZWISHLIWHIMGSPB9BDZGDZNQXDVTHHFRIIYFQHWFCD9LRDWZBAMHABLKOYGKILGV9DBK"
      "JZBOOSHLEIG9NJHRZCNNZAIYTZTPIDJNWFSNAMUNBBY9DMOI9ECDSWOHACKAZOYQAVYJPWMD"
      "YIQMLEU9WYCCPGCWUBOBORACRLEAIRZVEALJKPLPJFTPRWGPXCAJHVJ9CTHGYEDGDE9KXLUU"
      "BZDDT9RFJAMZGHNGHPIRGPEHHKOMJXXTQQNRKGORUCGZPLKPF9IXEBRRIDGWYGOHSTCTQWGY"
      "DDYTRAUQMPYDSHICWRLUBMHTEXRSAHXAKJSGQDEAATAIGWFGJMUKGPLYXFKCWRA9MHUSZBAU"
      "EUEBAGEDCUZXS9FCDQIJZNGCKZ9BZDTZUREZNYABOZOKSLYRLZ9DYFIOAVUNEVXSXYJFUYSS"
      "PISTPBMNMH9SWFQ9FCOOHSRWGNBEHHVFUYXKZBUWWXHFMYBDICTXZNIYQ9YGFGU9TXHOGFIN"
      "GUATJFUUCVZZFM9SAGJQOAOQTUWREJFWOEQFCNXPAKVRVKNILWRGISOY9WZHTU9WTUREVHSQ"
      "KTONDY9NDCNHDRNHOAIKCFSGW9WOTOPVLNDWAUTNVMALCLRDVWYFWSDCPQWHPWMQP9WY9PUV"
      "IKOIPFHNOPNS9OSZTHUJXOABLJRMGFEPZUNZMDZSXYNG9OMRJXJUVOMEELLGTLGATQCDVKPF"
      "YCQFDYHEKKKIODOSCNSRACPVJWGPLYABFIFKXHABSIABMDJJIYBPIWQEDLPLU9EYCPBVUVKZ"
      "SVGQQQIJJWTRJVVJARBACTNMHQBQNROFOPLAWITTVWYVMEPYQAPTPSQBLACQYTYZOWXGSMHW"
      "I9XV9XSUXJBFV9GZNRQVUJ9OOTQATHEJWPJSWPEEYZGQCJYNDBL9FUXILWGRVATPFYVUWGPD"
      "FSZIA9BMICESFCLYAFHOYAEDDXUUSXROOUXOLVLORXEHAMCJCYQWWYWXZUMJQGSJVQGQPMMI"
      "JQOLMGE9ZYAQCQLUSOSBXZTXVMCPCL9BRTVGZ9WEUJYYTFPFGPWPOMGKHMMHJVEHTWUOVY99"
      "FNBKAQMTCAJFQWQWPXZTHFYWJSJXDMCTCGAKJRJHXHPWAXEFRVOROBXWSWYXGRJ9PNNHDYVA"
      "NJDZQMZWKYFRFWGLPPWFPJNGJPDYKGTHGDBQPBODBPWFIHBBFEICJLXYEKDJMESTDIKYIYBK"
      "LMMKQTPORSFMUVJHWORTZSAQOKCVV9BKBXEXJVZOTZRWPBYNYEQDOKRMEITTJGU9WWGBOAMS"
      "CZTRGFNQNQRWTXIMSVOXVNR9GVDJWJVLYEXITUBQPY9VWXWFCRYBGNYWAUWASIBBAESNRNUM"
      "HLTLNR9LENCEUGMHQIYUINDGYWJQIHSTQBLPEFCDRYDHQSRFKJKWEAFBJDKRJFAXKIERXURB"
      "ZWIRCHOBJYTRDMJBBXUZZPZRANPCSSOJGV9HVYHOOEZFNPJOXIXKNPMZVGTPEZ9QGVCSKDAH"
      "GEVAZKILDUFZIICUJOLPKRNXJDXYKCNHRJFUJ9VSAIKGBLE9EUSTFDFNKGNHZR9PIWHUHAWB"
      "LEFJQM9NTDMOFVAKLOOWS9UCEZSRRDEJZBIZONFEYJZFRFMSFMMSCOPAXULAUKOVDOBXY9OJ"
      "AFIXT9NY99GLSIFY9ISFBQKUCQQZ9WVMLVRIQWYOGWUBIHLMJAXY99DJFOXMIIRBBGNVVUKE"
      "GMV99T9HTXML9EUZYADINHCSQISPTQXKTIHAWYCGYFTRFT99IHJCURQUYMVYKXSBYUALS9GK"
      "Q9LOWROQSZANOVISNYYZQK9KBKA";

  char* out_1 = iota_sign_signature_gen(SEED.c_str(), 2, 2, SEED.c_str());

  EXPECT_EQ(out_1, EX);

  free(out_1);
}

}  // namespace
