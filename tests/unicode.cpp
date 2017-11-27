/*
//  tests/unicode.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 07. 21:18
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Test for Unicode validate.
//  Character total can get from extracted/DerivedGeneralCategory.txt
*/
#include <seshat/codepoint.h>
#include <seshat/unicode/version.h>
#include <seshat/unicode/properties.h>

#include <cassert>
#include <cstdint>
#include <chrono>
#include <iostream>

using seshat::unicode::Version;
using seshat::unicode::UnicodeVersion;

#if (UNICODE_VERSION_MAJOR == 9)
#define CN_TOTAL 846359
#define LU_TOTAL 1702
#define LL_TOTAL 2063
#define LT_TOTAL 31
#define LM_TOTAL 249
#define LO_TOTAL 112721
#define MN_TOTAL 1690
#define ME_TOTAL 13
#define MC_TOTAL 394
#define ND_TOTAL 580
#define NL_TOTAL 236
#define NO_TOTAL 676
#define ZS_TOTAL 17
#define ZL_TOTAL 1
#define ZP_TOTAL 1
#define CC_TOTAL 65
#define CF_TOTAL 151
#define CO_TOTAL 137468
#define CS_TOTAL 2048
#define PD_TOTAL 24
#define PS_TOTAL 75
#define PE_TOTAL 73
#define PC_TOTAL 10
#define PO_TOTAL 544
#define SM_TOTAL 948
#define SC_TOTAL 53
#define SK_TOTAL 121
#define SO_TOTAL 5777
#define PI_TOTAL 12
#define PF_TOTAL 10
#elif (UNICODE_VERSION_MAJOR == 10)
#define CN_TOTAL 837841
#define LU_TOTAL 1702
#define LL_TOTAL 2063
#define LT_TOTAL 31
#define LM_TOTAL 250
#define LO_TOTAL 121047
#define MN_TOTAL 1763
#define ME_TOTAL 13
#define MC_TOTAL 401
#define ND_TOTAL 590
#define NL_TOTAL 236
#define NO_TOTAL 676
#define ZS_TOTAL 17
#define ZL_TOTAL 1
#define ZP_TOTAL 1
#define CC_TOTAL 65
#define CF_TOTAL 151
#define CO_TOTAL 137468
#define CS_TOTAL 2048
#define PD_TOTAL 24
#define PS_TOTAL 75
#define PE_TOTAL 73
#define PC_TOTAL 10
#define PO_TOTAL 566
#define SM_TOTAL 948
#define SC_TOTAL 54
#define SK_TOTAL 121
#define SO_TOTAL 5855
#define PI_TOTAL 12
#define PF_TOTAL 10
#endif
#define UNICODE_MAX 0x110000

static_assert(
    CN_TOTAL + LU_TOTAL + LL_TOTAL + LT_TOTAL + LM_TOTAL + LO_TOTAL +
    MN_TOTAL + ME_TOTAL + MC_TOTAL + ND_TOTAL + NL_TOTAL + NO_TOTAL +
    ZS_TOTAL + ZL_TOTAL + ZP_TOTAL + CC_TOTAL + CF_TOTAL + CO_TOTAL +
    CS_TOTAL + PD_TOTAL + PS_TOTAL + PE_TOTAL + PC_TOTAL + PO_TOTAL +
    SM_TOTAL + SC_TOTAL + SK_TOTAL + SO_TOTAL + PI_TOTAL + PF_TOTAL
    == UNICODE_MAX,
    "Total error.");

#include <cstdio>
void unicode_count_total()
{
    using seshat::CodePoint;
    using seshat::unicode::Gc;

    uint32_t cn_count = 0;
    uint32_t lu_count = 0;
    uint32_t ll_count = 0;
    uint32_t lt_count = 0;
    uint32_t lm_count = 0;
    uint32_t lo_count = 0;
    uint32_t mn_count = 0;
    uint32_t me_count = 0;
    uint32_t mc_count = 0;
    uint32_t nd_count = 0;
    uint32_t nl_count = 0;
    uint32_t no_count = 0;
    uint32_t zs_count = 0;
    uint32_t zl_count = 0;
    uint32_t zp_count = 0;
    uint32_t cc_count = 0;
    uint32_t cf_count = 0;
    uint32_t co_count = 0;
    uint32_t cs_count = 0;
    uint32_t pd_count = 0;
    uint32_t ps_count = 0;
    uint32_t pe_count = 0;
    uint32_t pc_count = 0;
    uint32_t po_count = 0;
    uint32_t sm_count = 0;
    uint32_t sc_count = 0;
    uint32_t sk_count = 0;
    uint32_t so_count = 0;
    uint32_t pi_count = 0;
    uint32_t pf_count = 0;

    auto start = std::chrono::steady_clock::now();

    for (uint32_t i = 0; i < UNICODE_MAX; ++i) {
        CodePoint cp = CodePoint(i);
        switch (seshat::unicode::gc(cp.code())) {
        case Gc::Cn:
            cn_count++;
            break;
        case Gc::Lu:
            lu_count++;
            break;
        case Gc::Ll:
            ll_count++;
            break;
        case Gc::Lt:
            lt_count++;
            break;
        case Gc::Lm:
            lm_count++;
            break;
        case Gc::Lo:
            lo_count++;
            break;
        case Gc::Mn:
            mn_count++;
            break;
        case Gc::Me:
            me_count++;
            break;
        case Gc::Mc:
            mc_count++;
            break;
        case Gc::Nd:
            nd_count++;
            break;
        case Gc::Nl:
            nl_count++;
            break;
        case Gc::No:
            no_count++;
            break;
        case Gc::Zs:
            zs_count++;
            break;
        case Gc::Zl:
            zl_count++;
            break;
        case Gc::Zp:
            zp_count++;
            break;
        case Gc::Cc:
            cc_count++;
            break;
        case Gc::Cf:
            cf_count++;
            break;
        case Gc::Co:
            co_count++;
            break;
        case Gc::Cs:
            cs_count++;
            break;
        case Gc::Pd:
            pd_count++;
            break;
        case Gc::Ps:
            ps_count++;
            break;
        case Gc::Pe:
            pe_count++;
            break;
        case Gc::Pc:
            pc_count++;
            break;
        case Gc::Po:
            po_count++;
            break;
        case Gc::Sm:
            sm_count++;
            break;
        case Gc::Sc:
            sc_count++;
            break;
        case Gc::Sk:
            sk_count++;
            break;
        case Gc::So:
            so_count++;
            break;
        case Gc::Pi:
            pi_count++;
            break;
        case Gc::Pf:
            pf_count++;
            break;
        default:
            assert(0);
        }
    } // for
    assert(cn_count == CN_TOTAL);
    assert(lu_count == LU_TOTAL);
    assert(ll_count == LL_TOTAL);
    assert(lt_count == LT_TOTAL);
    assert(lm_count == LM_TOTAL);
    assert(lo_count == LO_TOTAL);
    assert(mn_count == MN_TOTAL);
    assert(me_count == ME_TOTAL);
    assert(mc_count == MC_TOTAL);
    assert(nd_count == ND_TOTAL);
    assert(nl_count == NL_TOTAL);
    assert(no_count == NO_TOTAL);
    assert(zs_count == ZS_TOTAL);
    assert(zl_count == ZL_TOTAL);
    assert(zp_count == ZP_TOTAL);
    assert(cc_count == CC_TOTAL);
    assert(cf_count == CF_TOTAL);
    assert(co_count == CO_TOTAL);
    assert(cs_count == CS_TOTAL);
    assert(pd_count == PD_TOTAL);
    assert(ps_count == PS_TOTAL);
    assert(pe_count == PE_TOTAL);
    assert(pc_count == PC_TOTAL);
    assert(po_count == PO_TOTAL);
    assert(sm_count == SM_TOTAL);
    assert(sc_count == SC_TOTAL);
    assert(sk_count == SK_TOTAL);
    assert(so_count == SO_TOTAL);
    assert(pi_count == PI_TOTAL);
    assert(pf_count == PF_TOTAL);

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    std::cout << "Test passed in "
        << std::chrono::duration<double>(diff).count() << " sec"
        << std::endl;
} // unicode_count_total

int main()
{
    unicode_count_total();

    return 0;
}
