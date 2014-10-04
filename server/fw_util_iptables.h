/*
 *****************************************************************************
 *
 * File:    fw_util_iptables.h
 *
 * Purpose: Header file for fw_util_iptables.c.
 *
 *  Fwknop is developed primarily by the people listed in the file 'AUTHORS'.
 *  Copyright (C) 2009-2014 fwknop developers and contributors. For a full
 *  list of contributors, see the file 'CREDITS'.
 *
 *  License (GNU General Public License):
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *****************************************************************************
*/
#ifndef FW_UTIL_IPTABLES_H
#define FW_UTIL_IPTABLES_H

#define SNAT_TARGET_BUFSIZE         64

/* iptables command args
*/
#define IPT_CHK_RULE_ARGS       "-C %s %s"
#define IPT_RULE_ARGS           "-t %s -p %i -s %s --dport %i -m comment --comment " EXPIRE_COMMENT_PREFIX "%u -j %s"
#define IPT_OUT_RULE_ARGS       "-t %s -p %i -d %s --sport %i -m comment --comment " EXPIRE_COMMENT_PREFIX "%u -j %s"
#define IPT_FWD_RULE_ARGS       "-t %s -p %i -s %s -d %s --dport %i -m comment --comment " EXPIRE_COMMENT_PREFIX "%u -j %s"
#define IPT_DNAT_RULE_ARGS      "-t %s -p %i -s %s --dport %i -m comment --comment " EXPIRE_COMMENT_PREFIX "%u -j %s --to-destination %s:%i"
#define IPT_SNAT_RULE_ARGS      "-t %s -p %i -d %s --dport %i -m comment --comment " EXPIRE_COMMENT_PREFIX "%u -j %s %s"
#define IPT_TMP_COMMENT_ARGS    "-t %s -I %s %i -s 127.0.0.2 -m comment --comment " TMP_COMMENT " -j %s"
#define IPT_TMP_CHK_RULE_ARGS   "-t %s -I %s %i -s 127.0.0.2 -p udp -j %s"
#define IPT_TMP_VERIFY_CHK_ARGS "-t %s -C %s -s 127.0.0.2 -p udp -j %s"
#define IPT_DEL_RULE_ARGS       "-t %s -D %s %i"
#define IPT_NEW_CHAIN_ARGS      "-t %s -N %s"
#define IPT_FLUSH_CHAIN_ARGS    "-t %s -F %s"
#define IPT_CHAIN_EXISTS_ARGS   "-t %s -L %s -n"
#define IPT_DEL_CHAIN_ARGS      "-t %s -X %s"
#define IPT_CHK_JUMP_RULE_ARGS  "-t %s -j %s"
#define IPT_ADD_JUMP_RULE_ARGS  "-t %s -I %s %i -j %s"
#define IPT_DEL_JUMP_RULE_ARGS  "-t %s -D %s -j %s"  /* let iptables work out the rule number */
#define IPT_LIST_RULES_ARGS     "-t %s -L %s --line-numbers -n"
#define IPT_LIST_ALL_RULES_ARGS "-t %s -v -n -L --line-numbers"

int validate_ipt_chain_conf(const char * const chain_str);

#endif /* FW_UTIL_IPTABLES_H */

/***EOF***/
