pw_with_fixes = []
pw_no_fixes = []
for d in open('singularities_detection_manual_fixes.md').readlines():
    if d.startswith('No of piecewises: '):
        d = d.replace('No of piecewises: ', '')
        pw_with_fixes.append(int(d))

for d in open('singularities_detection_no_fixes.md').readlines():
    if d.startswith('No of piecewises: '):
        d = d.replace('No of piecewises: ', '')
        pw_no_fixes.append(int(d))

sing_with_fixes = []
sing_no_fixes = []
for d in open('singularities_detection_manual_fixes.md').readlines():
    if d.startswith('# of singularities:  '):
        d = d.replace('# of singularities:  ', '')
        sing_with_fixes.append(int(d))


for d in open('singularities_detection_no_fixes.md').readlines():
    if d.startswith('# of singularities:  '):
        d = d.replace('# of singularities:  ', '')
        sing_no_fixes.append(int(d))

models = ["aslanidi_atrial_model_2009", "aslanidi_2009", "beeler_reuter_model_1977", "benson_epicardial_2008", "bernus_wilders_zemlin_verschelde_panfilov_ 2002_version01", "bondarenko_2004_apical", "bondarenko_2004_septum", "bueno_2007 (bueno_2007_endo.cellml)", "bueno_2007 (bueno_2007_epi.cellml)", "Carro_Rodriguez_Laguna_Pueyo_CinC2010_EPI (carro_2011_endo.cellml)", "Carro_Rodriguez_Laguna_Pueyo_CinC2010_EPI (carro_2011_epi.cellml)", "clancy_rudy_2002", "Corrias_rabbit_purkinje_model", "courtemanche_1998", "davies_isap_2012", "decker_2009", "demir_model_1994", "difrancesco_noble_model_1985", "dokos_model_1996", "earm_noble_model_1990", "espinosa_model_1998", "faber_rudy_2000", "fink_noble_giles_model_2008", "fox_model_2001", "grandi_pasqualini_bers_2010 (grandi_pasqualini_bers_2010_ss.cellml)", "grandi_pasqualini_bers_2010 (grandi_pasqualini_bers_2010_ss_endo.cellml)", "hilgemann_noble_model_1987", "hodgkin_huxley_squid_axon_model_1952_ modified", "HundRudy2004_units", "iribe_model_2006", "IyerMazhariWinslow2004", "iyer_model_2007", "jafri_rice_winslow_1998", "kurata_model_2002", "lindblad_atrial_model_1996", "LivshitzRudy2007", "Li_Mouse_2010", "luo_rudy_1991", "luo_rudy_1994", "MahajanShiferaw2008_units", "Maleckar", "maltsev_2009", "matsuoka_model_2003", "mcallister_noble_tsien_1975_modelB", "noble_model_1962", "noble_model_1991", "noble_model_1998", "noble_model_2001", "NN_SAN_model_1984", "Noble_SAN_model_1989", "nygren_atrial_model_1998", "ohara_rudy_2011_endo", "ohara_rudy_2011_epi", "ohara_rudy_cipa_v1_2017", "paci_hyttinen_aaltosetala_severi_atrial Version", "paci_hyttinen_aaltosetala_severi_ventricular Version", "pandit_clark_giles_demir_2001_ version06_variant01", "pandit_clark_giles_demir_2001", "pasek_simurda_christe_2006", "pasek_model_2008", "priebe_beuckelmann_1998", "ramirez_2000", "sachse_model_2007", "sakmann_model_2000_epi", "shannon_wang_puglisi_weber_bers_2004_model_ updated", "stewart_zhang_model_2008", "tentusscher_model_2004_endo", "tentusscher_model_2004_epi", "tentusscher_model_2004_M", "tentusscher_model_2006_endo", "tentusscher_model_2006_epi", "tentusscher_model_2006_M", "Tomek_model13endo", "Tomek_model13epi", "Trovato2020", "viswanathan_model_1999_epi", "wang_model_2008", "winslow_model_1999", "zhang_SAN_model_2000_0D_capable"]
print("""
|Model 	                                                                 |PW* with fixes|PW no fixes|PW diff|Sing** with fixes|Sing no fixes|sing diff|PW diff == sing diff|
|---                                                                     |---|---|---|---|---|---|---|""")
for i, m in enumerate(models):
    space = " "*(72-len(models[i]))
    print(f"|{models[i]}{space}|{pw_with_fixes[i]}  |{pw_no_fixes[i]}  |{pw_with_fixes[i]-pw_no_fixes[i]}  |{sing_with_fixes[i]}  |{sing_no_fixes[i]}  |{sing_no_fixes[i]-sing_with_fixes[i]}  |{(pw_with_fixes[i]-pw_no_fixes[i]) == (sing_no_fixes[i]-sing_with_fixes[i])} |")



