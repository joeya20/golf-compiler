
	.text
	.globl main
main:
	jal Lmain
	j halt
Lmain:
	# prologue
	addiu $sp, $sp, -8
	sw   $ra, 4($sp)
	sw   $fp, 0($sp)
	move $fp, $sp
	addiu $sp, $sp, -12
	# body
	sw $0, -4($fp)		# initializing var i
	sw $0, -8($fp)		# initializing var j
	sw $0, -12($fp)		# initializing var n
	li $t0, 1
	sw $t0, -4($fp)
L2:
	lw $t0, -4($fp)
	li $t1, 100
	sle $t0, $t0, $t1
	beq $t0, $0, L3
	lw $t0, -4($fp)
	li $t1, 1
	seq $t0, $t0, $t1
	beq $t0, $0, L5
	li $t0, 0
	sw $t0, LA_1
	j L4
L5:
	lw $t0, -4($fp)
	li $t1, 2
	seq $t0, $t0, $t1
	beq $t0, $0, L7
	li $t0, 0
	sw $t0, LA_2
	j L6
L7:
	lw $t0, -4($fp)
	li $t1, 3
	seq $t0, $t0, $t1
	beq $t0, $0, L9
	li $t0, 0
	sw $t0, LA_3
	j L8
L9:
	lw $t0, -4($fp)
	li $t1, 4
	seq $t0, $t0, $t1
	beq $t0, $0, L11
	li $t0, 0
	sw $t0, LA_4
	j L10
L11:
	lw $t0, -4($fp)
	li $t1, 5
	seq $t0, $t0, $t1
	beq $t0, $0, L13
	li $t0, 0
	sw $t0, LA_5
	j L12
L13:
	lw $t0, -4($fp)
	li $t1, 6
	seq $t0, $t0, $t1
	beq $t0, $0, L15
	li $t0, 0
	sw $t0, LA_6
	j L14
L15:
	lw $t0, -4($fp)
	li $t1, 7
	seq $t0, $t0, $t1
	beq $t0, $0, L17
	li $t0, 0
	sw $t0, LA_7
	j L16
L17:
	lw $t0, -4($fp)
	li $t1, 8
	seq $t0, $t0, $t1
	beq $t0, $0, L19
	li $t0, 0
	sw $t0, LA_8
	j L18
L19:
	lw $t0, -4($fp)
	li $t1, 9
	seq $t0, $t0, $t1
	beq $t0, $0, L21
	li $t0, 0
	sw $t0, LA_9
	j L20
L21:
	lw $t0, -4($fp)
	li $t1, 10
	seq $t0, $t0, $t1
	beq $t0, $0, L23
	li $t0, 0
	sw $t0, LA_10
	j L22
L23:
	lw $t0, -4($fp)
	li $t1, 11
	seq $t0, $t0, $t1
	beq $t0, $0, L25
	li $t0, 0
	sw $t0, LA_11
	j L24
L25:
	lw $t0, -4($fp)
	li $t1, 12
	seq $t0, $t0, $t1
	beq $t0, $0, L27
	li $t0, 0
	sw $t0, LA_12
	j L26
L27:
	lw $t0, -4($fp)
	li $t1, 13
	seq $t0, $t0, $t1
	beq $t0, $0, L29
	li $t0, 0
	sw $t0, LA_13
	j L28
L29:
	lw $t0, -4($fp)
	li $t1, 14
	seq $t0, $t0, $t1
	beq $t0, $0, L31
	li $t0, 0
	sw $t0, LA_14
	j L30
L31:
	lw $t0, -4($fp)
	li $t1, 15
	seq $t0, $t0, $t1
	beq $t0, $0, L33
	li $t0, 0
	sw $t0, LA_15
	j L32
L33:
	lw $t0, -4($fp)
	li $t1, 16
	seq $t0, $t0, $t1
	beq $t0, $0, L35
	li $t0, 0
	sw $t0, LA_16
	j L34
L35:
	lw $t0, -4($fp)
	li $t1, 17
	seq $t0, $t0, $t1
	beq $t0, $0, L37
	li $t0, 0
	sw $t0, LA_17
	j L36
L37:
	lw $t0, -4($fp)
	li $t1, 18
	seq $t0, $t0, $t1
	beq $t0, $0, L39
	li $t0, 0
	sw $t0, LA_18
	j L38
L39:
	lw $t0, -4($fp)
	li $t1, 19
	seq $t0, $t0, $t1
	beq $t0, $0, L41
	li $t0, 0
	sw $t0, LA_19
	j L40
L41:
	lw $t0, -4($fp)
	li $t1, 20
	seq $t0, $t0, $t1
	beq $t0, $0, L43
	li $t0, 0
	sw $t0, LA_20
	j L42
L43:
	lw $t0, -4($fp)
	li $t1, 21
	seq $t0, $t0, $t1
	beq $t0, $0, L45
	li $t0, 0
	sw $t0, LA_21
	j L44
L45:
	lw $t0, -4($fp)
	li $t1, 22
	seq $t0, $t0, $t1
	beq $t0, $0, L47
	li $t0, 0
	sw $t0, LA_22
	j L46
L47:
	lw $t0, -4($fp)
	li $t1, 23
	seq $t0, $t0, $t1
	beq $t0, $0, L49
	li $t0, 0
	sw $t0, LA_23
	j L48
L49:
	lw $t0, -4($fp)
	li $t1, 24
	seq $t0, $t0, $t1
	beq $t0, $0, L51
	li $t0, 0
	sw $t0, LA_24
	j L50
L51:
	lw $t0, -4($fp)
	li $t1, 25
	seq $t0, $t0, $t1
	beq $t0, $0, L53
	li $t0, 0
	sw $t0, LA_25
	j L52
L53:
	lw $t0, -4($fp)
	li $t1, 26
	seq $t0, $t0, $t1
	beq $t0, $0, L55
	li $t0, 0
	sw $t0, LA_26
	j L54
L55:
	lw $t0, -4($fp)
	li $t1, 27
	seq $t0, $t0, $t1
	beq $t0, $0, L57
	li $t0, 0
	sw $t0, LA_27
	j L56
L57:
	lw $t0, -4($fp)
	li $t1, 28
	seq $t0, $t0, $t1
	beq $t0, $0, L59
	li $t0, 0
	sw $t0, LA_28
	j L58
L59:
	lw $t0, -4($fp)
	li $t1, 29
	seq $t0, $t0, $t1
	beq $t0, $0, L61
	li $t0, 0
	sw $t0, LA_29
	j L60
L61:
	lw $t0, -4($fp)
	li $t1, 30
	seq $t0, $t0, $t1
	beq $t0, $0, L63
	li $t0, 0
	sw $t0, LA_30
	j L62
L63:
	lw $t0, -4($fp)
	li $t1, 31
	seq $t0, $t0, $t1
	beq $t0, $0, L65
	li $t0, 0
	sw $t0, LA_31
	j L64
L65:
	lw $t0, -4($fp)
	li $t1, 32
	seq $t0, $t0, $t1
	beq $t0, $0, L67
	li $t0, 0
	sw $t0, LA_32
	j L66
L67:
	lw $t0, -4($fp)
	li $t1, 33
	seq $t0, $t0, $t1
	beq $t0, $0, L69
	li $t0, 0
	sw $t0, LA_33
	j L68
L69:
	lw $t0, -4($fp)
	li $t1, 34
	seq $t0, $t0, $t1
	beq $t0, $0, L71
	li $t0, 0
	sw $t0, LA_34
	j L70
L71:
	lw $t0, -4($fp)
	li $t1, 35
	seq $t0, $t0, $t1
	beq $t0, $0, L73
	li $t0, 0
	sw $t0, LA_35
	j L72
L73:
	lw $t0, -4($fp)
	li $t1, 36
	seq $t0, $t0, $t1
	beq $t0, $0, L75
	li $t0, 0
	sw $t0, LA_36
	j L74
L75:
	lw $t0, -4($fp)
	li $t1, 37
	seq $t0, $t0, $t1
	beq $t0, $0, L77
	li $t0, 0
	sw $t0, LA_37
	j L76
L77:
	lw $t0, -4($fp)
	li $t1, 38
	seq $t0, $t0, $t1
	beq $t0, $0, L79
	li $t0, 0
	sw $t0, LA_38
	j L78
L79:
	lw $t0, -4($fp)
	li $t1, 39
	seq $t0, $t0, $t1
	beq $t0, $0, L81
	li $t0, 0
	sw $t0, LA_39
	j L80
L81:
	lw $t0, -4($fp)
	li $t1, 40
	seq $t0, $t0, $t1
	beq $t0, $0, L83
	li $t0, 0
	sw $t0, LA_40
	j L82
L83:
	lw $t0, -4($fp)
	li $t1, 41
	seq $t0, $t0, $t1
	beq $t0, $0, L85
	li $t0, 0
	sw $t0, LA_41
	j L84
L85:
	lw $t0, -4($fp)
	li $t1, 42
	seq $t0, $t0, $t1
	beq $t0, $0, L87
	li $t0, 0
	sw $t0, LA_42
	j L86
L87:
	lw $t0, -4($fp)
	li $t1, 43
	seq $t0, $t0, $t1
	beq $t0, $0, L89
	li $t0, 0
	sw $t0, LA_43
	j L88
L89:
	lw $t0, -4($fp)
	li $t1, 44
	seq $t0, $t0, $t1
	beq $t0, $0, L91
	li $t0, 0
	sw $t0, LA_44
	j L90
L91:
	lw $t0, -4($fp)
	li $t1, 45
	seq $t0, $t0, $t1
	beq $t0, $0, L93
	li $t0, 0
	sw $t0, LA_45
	j L92
L93:
	lw $t0, -4($fp)
	li $t1, 46
	seq $t0, $t0, $t1
	beq $t0, $0, L95
	li $t0, 0
	sw $t0, LA_46
	j L94
L95:
	lw $t0, -4($fp)
	li $t1, 47
	seq $t0, $t0, $t1
	beq $t0, $0, L97
	li $t0, 0
	sw $t0, LA_47
	j L96
L97:
	lw $t0, -4($fp)
	li $t1, 48
	seq $t0, $t0, $t1
	beq $t0, $0, L99
	li $t0, 0
	sw $t0, LA_48
	j L98
L99:
	lw $t0, -4($fp)
	li $t1, 49
	seq $t0, $t0, $t1
	beq $t0, $0, L101
	li $t0, 0
	sw $t0, LA_49
	j L100
L101:
	lw $t0, -4($fp)
	li $t1, 50
	seq $t0, $t0, $t1
	beq $t0, $0, L103
	li $t0, 0
	sw $t0, LA_50
	j L102
L103:
	lw $t0, -4($fp)
	li $t1, 51
	seq $t0, $t0, $t1
	beq $t0, $0, L105
	li $t0, 0
	sw $t0, LA_51
	j L104
L105:
	lw $t0, -4($fp)
	li $t1, 52
	seq $t0, $t0, $t1
	beq $t0, $0, L107
	li $t0, 0
	sw $t0, LA_52
	j L106
L107:
	lw $t0, -4($fp)
	li $t1, 53
	seq $t0, $t0, $t1
	beq $t0, $0, L109
	li $t0, 0
	sw $t0, LA_53
	j L108
L109:
	lw $t0, -4($fp)
	li $t1, 54
	seq $t0, $t0, $t1
	beq $t0, $0, L111
	li $t0, 0
	sw $t0, LA_54
	j L110
L111:
	lw $t0, -4($fp)
	li $t1, 55
	seq $t0, $t0, $t1
	beq $t0, $0, L113
	li $t0, 0
	sw $t0, LA_55
	j L112
L113:
	lw $t0, -4($fp)
	li $t1, 56
	seq $t0, $t0, $t1
	beq $t0, $0, L115
	li $t0, 0
	sw $t0, LA_56
	j L114
L115:
	lw $t0, -4($fp)
	li $t1, 57
	seq $t0, $t0, $t1
	beq $t0, $0, L117
	li $t0, 0
	sw $t0, LA_57
	j L116
L117:
	lw $t0, -4($fp)
	li $t1, 58
	seq $t0, $t0, $t1
	beq $t0, $0, L119
	li $t0, 0
	sw $t0, LA_58
	j L118
L119:
	lw $t0, -4($fp)
	li $t1, 59
	seq $t0, $t0, $t1
	beq $t0, $0, L121
	li $t0, 0
	sw $t0, LA_59
	j L120
L121:
	lw $t0, -4($fp)
	li $t1, 60
	seq $t0, $t0, $t1
	beq $t0, $0, L123
	li $t0, 0
	sw $t0, LA_60
	j L122
L123:
	lw $t0, -4($fp)
	li $t1, 61
	seq $t0, $t0, $t1
	beq $t0, $0, L125
	li $t0, 0
	sw $t0, LA_61
	j L124
L125:
	lw $t0, -4($fp)
	li $t1, 62
	seq $t0, $t0, $t1
	beq $t0, $0, L127
	li $t0, 0
	sw $t0, LA_62
	j L126
L127:
	lw $t0, -4($fp)
	li $t1, 63
	seq $t0, $t0, $t1
	beq $t0, $0, L129
	li $t0, 0
	sw $t0, LA_63
	j L128
L129:
	lw $t0, -4($fp)
	li $t1, 64
	seq $t0, $t0, $t1
	beq $t0, $0, L131
	li $t0, 0
	sw $t0, LA_64
	j L130
L131:
	lw $t0, -4($fp)
	li $t1, 65
	seq $t0, $t0, $t1
	beq $t0, $0, L133
	li $t0, 0
	sw $t0, LA_65
	j L132
L133:
	lw $t0, -4($fp)
	li $t1, 66
	seq $t0, $t0, $t1
	beq $t0, $0, L135
	li $t0, 0
	sw $t0, LA_66
	j L134
L135:
	lw $t0, -4($fp)
	li $t1, 67
	seq $t0, $t0, $t1
	beq $t0, $0, L137
	li $t0, 0
	sw $t0, LA_67
	j L136
L137:
	lw $t0, -4($fp)
	li $t1, 68
	seq $t0, $t0, $t1
	beq $t0, $0, L139
	li $t0, 0
	sw $t0, LA_68
	j L138
L139:
	lw $t0, -4($fp)
	li $t1, 69
	seq $t0, $t0, $t1
	beq $t0, $0, L141
	li $t0, 0
	sw $t0, LA_69
	j L140
L141:
	lw $t0, -4($fp)
	li $t1, 70
	seq $t0, $t0, $t1
	beq $t0, $0, L143
	li $t0, 0
	sw $t0, LA_70
	j L142
L143:
	lw $t0, -4($fp)
	li $t1, 71
	seq $t0, $t0, $t1
	beq $t0, $0, L145
	li $t0, 0
	sw $t0, LA_71
	j L144
L145:
	lw $t0, -4($fp)
	li $t1, 72
	seq $t0, $t0, $t1
	beq $t0, $0, L147
	li $t0, 0
	sw $t0, LA_72
	j L146
L147:
	lw $t0, -4($fp)
	li $t1, 73
	seq $t0, $t0, $t1
	beq $t0, $0, L149
	li $t0, 0
	sw $t0, LA_73
	j L148
L149:
	lw $t0, -4($fp)
	li $t1, 74
	seq $t0, $t0, $t1
	beq $t0, $0, L151
	li $t0, 0
	sw $t0, LA_74
	j L150
L151:
	lw $t0, -4($fp)
	li $t1, 75
	seq $t0, $t0, $t1
	beq $t0, $0, L153
	li $t0, 0
	sw $t0, LA_75
	j L152
L153:
	lw $t0, -4($fp)
	li $t1, 76
	seq $t0, $t0, $t1
	beq $t0, $0, L155
	li $t0, 0
	sw $t0, LA_76
	j L154
L155:
	lw $t0, -4($fp)
	li $t1, 77
	seq $t0, $t0, $t1
	beq $t0, $0, L157
	li $t0, 0
	sw $t0, LA_77
	j L156
L157:
	lw $t0, -4($fp)
	li $t1, 78
	seq $t0, $t0, $t1
	beq $t0, $0, L159
	li $t0, 0
	sw $t0, LA_78
	j L158
L159:
	lw $t0, -4($fp)
	li $t1, 79
	seq $t0, $t0, $t1
	beq $t0, $0, L161
	li $t0, 0
	sw $t0, LA_79
	j L160
L161:
	lw $t0, -4($fp)
	li $t1, 80
	seq $t0, $t0, $t1
	beq $t0, $0, L163
	li $t0, 0
	sw $t0, LA_80
	j L162
L163:
	lw $t0, -4($fp)
	li $t1, 81
	seq $t0, $t0, $t1
	beq $t0, $0, L165
	li $t0, 0
	sw $t0, LA_81
	j L164
L165:
	lw $t0, -4($fp)
	li $t1, 82
	seq $t0, $t0, $t1
	beq $t0, $0, L167
	li $t0, 0
	sw $t0, LA_82
	j L166
L167:
	lw $t0, -4($fp)
	li $t1, 83
	seq $t0, $t0, $t1
	beq $t0, $0, L169
	li $t0, 0
	sw $t0, LA_83
	j L168
L169:
	lw $t0, -4($fp)
	li $t1, 84
	seq $t0, $t0, $t1
	beq $t0, $0, L171
	li $t0, 0
	sw $t0, LA_84
	j L170
L171:
	lw $t0, -4($fp)
	li $t1, 85
	seq $t0, $t0, $t1
	beq $t0, $0, L173
	li $t0, 0
	sw $t0, LA_85
	j L172
L173:
	lw $t0, -4($fp)
	li $t1, 86
	seq $t0, $t0, $t1
	beq $t0, $0, L175
	li $t0, 0
	sw $t0, LA_86
	j L174
L175:
	lw $t0, -4($fp)
	li $t1, 87
	seq $t0, $t0, $t1
	beq $t0, $0, L177
	li $t0, 0
	sw $t0, LA_87
	j L176
L177:
	lw $t0, -4($fp)
	li $t1, 88
	seq $t0, $t0, $t1
	beq $t0, $0, L179
	li $t0, 0
	sw $t0, LA_88
	j L178
L179:
	lw $t0, -4($fp)
	li $t1, 89
	seq $t0, $t0, $t1
	beq $t0, $0, L181
	li $t0, 0
	sw $t0, LA_89
	j L180
L181:
	lw $t0, -4($fp)
	li $t1, 90
	seq $t0, $t0, $t1
	beq $t0, $0, L183
	li $t0, 0
	sw $t0, LA_90
	j L182
L183:
	lw $t0, -4($fp)
	li $t1, 91
	seq $t0, $t0, $t1
	beq $t0, $0, L185
	li $t0, 0
	sw $t0, LA_91
	j L184
L185:
	lw $t0, -4($fp)
	li $t1, 92
	seq $t0, $t0, $t1
	beq $t0, $0, L187
	li $t0, 0
	sw $t0, LA_92
	j L186
L187:
	lw $t0, -4($fp)
	li $t1, 93
	seq $t0, $t0, $t1
	beq $t0, $0, L189
	li $t0, 0
	sw $t0, LA_93
	j L188
L189:
	lw $t0, -4($fp)
	li $t1, 94
	seq $t0, $t0, $t1
	beq $t0, $0, L191
	li $t0, 0
	sw $t0, LA_94
	j L190
L191:
	lw $t0, -4($fp)
	li $t1, 95
	seq $t0, $t0, $t1
	beq $t0, $0, L193
	li $t0, 0
	sw $t0, LA_95
	j L192
L193:
	lw $t0, -4($fp)
	li $t1, 96
	seq $t0, $t0, $t1
	beq $t0, $0, L195
	li $t0, 0
	sw $t0, LA_96
	j L194
L195:
	lw $t0, -4($fp)
	li $t1, 97
	seq $t0, $t0, $t1
	beq $t0, $0, L197
	li $t0, 0
	sw $t0, LA_97
	j L196
L197:
	lw $t0, -4($fp)
	li $t1, 98
	seq $t0, $t0, $t1
	beq $t0, $0, L199
	li $t0, 0
	sw $t0, LA_98
	j L198
L199:
	lw $t0, -4($fp)
	li $t1, 99
	seq $t0, $t0, $t1
	beq $t0, $0, L201
	li $t0, 0
	sw $t0, LA_99
	j L200
L201:
	lw $t0, -4($fp)
	li $t1, 100
	seq $t0, $t0, $t1
	beq $t0, $0, L202
	li $t0, 0
	sw $t0, LA_100
L202:
L200:
L198:
L196:
L194:
L192:
L190:
L188:
L186:
L184:
L182:
L180:
L178:
L176:
L174:
L172:
L170:
L168:
L166:
L164:
L162:
L160:
L158:
L156:
L154:
L152:
L150:
L148:
L146:
L144:
L142:
L140:
L138:
L136:
L134:
L132:
L130:
L128:
L126:
L124:
L122:
L120:
L118:
L116:
L114:
L112:
L110:
L108:
L106:
L104:
L102:
L100:
L98:
L96:
L94:
L92:
L90:
L88:
L86:
L84:
L82:
L80:
L78:
L76:
L74:
L72:
L70:
L68:
L66:
L64:
L62:
L60:
L58:
L56:
L54:
L52:
L50:
L48:
L46:
L44:
L42:
L40:
L38:
L36:
L34:
L32:
L30:
L28:
L26:
L24:
L22:
L20:
L18:
L16:
L14:
L12:
L10:
L8:
L6:
L4:
	lw $t0, -4($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -4($fp)
	j L2
L3:
	li $t0, 2
	sw $t0, -4($fp)
L203:
	lw $t0, -4($fp)
	li $t1, 10
	sle $t0, $t0, $t1
	beq $t0, $0, L204
	lw $t0, -4($fp)
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
L205:
	lw $t0, -8($fp)
	li $t1, 100
	sle $t0, $t0, $t1
	beq $t0, $0, L206
	lw $t0, -8($fp)
	li $t1, 2
	seq $t0, $t0, $t1
	beq $t0, $0, L208
	li $t0, 1
	sw $t0, LA_2
	li $t0, 2
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L207
L208:
	lw $t0, -8($fp)
	li $t1, 3
	seq $t0, $t0, $t1
	beq $t0, $0, L210
	li $t0, 1
	sw $t0, LA_3
	li $t0, 3
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L209
L210:
	lw $t0, -8($fp)
	li $t1, 4
	seq $t0, $t0, $t1
	beq $t0, $0, L212
	li $t0, 1
	sw $t0, LA_4
	li $t0, 4
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L211
L212:
	lw $t0, -8($fp)
	li $t1, 5
	seq $t0, $t0, $t1
	beq $t0, $0, L214
	li $t0, 1
	sw $t0, LA_5
	li $t0, 5
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L213
L214:
	lw $t0, -8($fp)
	li $t1, 6
	seq $t0, $t0, $t1
	beq $t0, $0, L216
	li $t0, 1
	sw $t0, LA_6
	li $t0, 6
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L215
L216:
	lw $t0, -8($fp)
	li $t1, 7
	seq $t0, $t0, $t1
	beq $t0, $0, L218
	li $t0, 1
	sw $t0, LA_7
	li $t0, 7
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L217
L218:
	lw $t0, -8($fp)
	li $t1, 8
	seq $t0, $t0, $t1
	beq $t0, $0, L220
	li $t0, 1
	sw $t0, LA_8
	li $t0, 8
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L219
L220:
	lw $t0, -8($fp)
	li $t1, 9
	seq $t0, $t0, $t1
	beq $t0, $0, L222
	li $t0, 1
	sw $t0, LA_9
	li $t0, 9
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L221
L222:
	lw $t0, -8($fp)
	li $t1, 10
	seq $t0, $t0, $t1
	beq $t0, $0, L224
	li $t0, 1
	sw $t0, LA_10
	li $t0, 10
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L223
L224:
	lw $t0, -8($fp)
	li $t1, 11
	seq $t0, $t0, $t1
	beq $t0, $0, L226
	li $t0, 1
	sw $t0, LA_11
	li $t0, 11
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L225
L226:
	lw $t0, -8($fp)
	li $t1, 12
	seq $t0, $t0, $t1
	beq $t0, $0, L228
	li $t0, 1
	sw $t0, LA_12
	li $t0, 12
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L227
L228:
	lw $t0, -8($fp)
	li $t1, 13
	seq $t0, $t0, $t1
	beq $t0, $0, L230
	li $t0, 1
	sw $t0, LA_13
	li $t0, 13
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L229
L230:
	lw $t0, -8($fp)
	li $t1, 14
	seq $t0, $t0, $t1
	beq $t0, $0, L232
	li $t0, 1
	sw $t0, LA_14
	li $t0, 14
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L231
L232:
	lw $t0, -8($fp)
	li $t1, 15
	seq $t0, $t0, $t1
	beq $t0, $0, L234
	li $t0, 1
	sw $t0, LA_15
	li $t0, 15
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L233
L234:
	lw $t0, -8($fp)
	li $t1, 16
	seq $t0, $t0, $t1
	beq $t0, $0, L236
	li $t0, 1
	sw $t0, LA_16
	li $t0, 16
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L235
L236:
	lw $t0, -8($fp)
	li $t1, 17
	seq $t0, $t0, $t1
	beq $t0, $0, L238
	li $t0, 1
	sw $t0, LA_17
	li $t0, 17
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L237
L238:
	lw $t0, -8($fp)
	li $t1, 18
	seq $t0, $t0, $t1
	beq $t0, $0, L240
	li $t0, 1
	sw $t0, LA_18
	li $t0, 18
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L239
L240:
	lw $t0, -8($fp)
	li $t1, 19
	seq $t0, $t0, $t1
	beq $t0, $0, L242
	li $t0, 1
	sw $t0, LA_19
	li $t0, 19
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L241
L242:
	lw $t0, -8($fp)
	li $t1, 20
	seq $t0, $t0, $t1
	beq $t0, $0, L244
	li $t0, 1
	sw $t0, LA_20
	li $t0, 20
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L243
L244:
	lw $t0, -8($fp)
	li $t1, 21
	seq $t0, $t0, $t1
	beq $t0, $0, L246
	li $t0, 1
	sw $t0, LA_21
	li $t0, 21
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L245
L246:
	lw $t0, -8($fp)
	li $t1, 22
	seq $t0, $t0, $t1
	beq $t0, $0, L248
	li $t0, 1
	sw $t0, LA_22
	li $t0, 22
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L247
L248:
	lw $t0, -8($fp)
	li $t1, 23
	seq $t0, $t0, $t1
	beq $t0, $0, L250
	li $t0, 1
	sw $t0, LA_23
	li $t0, 23
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L249
L250:
	lw $t0, -8($fp)
	li $t1, 24
	seq $t0, $t0, $t1
	beq $t0, $0, L252
	li $t0, 1
	sw $t0, LA_24
	li $t0, 24
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L251
L252:
	lw $t0, -8($fp)
	li $t1, 25
	seq $t0, $t0, $t1
	beq $t0, $0, L254
	li $t0, 1
	sw $t0, LA_25
	li $t0, 25
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L253
L254:
	lw $t0, -8($fp)
	li $t1, 26
	seq $t0, $t0, $t1
	beq $t0, $0, L256
	li $t0, 1
	sw $t0, LA_26
	li $t0, 26
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L255
L256:
	lw $t0, -8($fp)
	li $t1, 27
	seq $t0, $t0, $t1
	beq $t0, $0, L258
	li $t0, 1
	sw $t0, LA_27
	li $t0, 27
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L257
L258:
	lw $t0, -8($fp)
	li $t1, 28
	seq $t0, $t0, $t1
	beq $t0, $0, L260
	li $t0, 1
	sw $t0, LA_28
	li $t0, 28
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L259
L260:
	lw $t0, -8($fp)
	li $t1, 29
	seq $t0, $t0, $t1
	beq $t0, $0, L262
	li $t0, 1
	sw $t0, LA_29
	li $t0, 29
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L261
L262:
	lw $t0, -8($fp)
	li $t1, 30
	seq $t0, $t0, $t1
	beq $t0, $0, L264
	li $t0, 1
	sw $t0, LA_30
	li $t0, 30
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L263
L264:
	lw $t0, -8($fp)
	li $t1, 31
	seq $t0, $t0, $t1
	beq $t0, $0, L266
	li $t0, 1
	sw $t0, LA_31
	li $t0, 31
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L265
L266:
	lw $t0, -8($fp)
	li $t1, 32
	seq $t0, $t0, $t1
	beq $t0, $0, L268
	li $t0, 1
	sw $t0, LA_32
	li $t0, 32
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L267
L268:
	lw $t0, -8($fp)
	li $t1, 33
	seq $t0, $t0, $t1
	beq $t0, $0, L270
	li $t0, 1
	sw $t0, LA_33
	li $t0, 33
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L269
L270:
	lw $t0, -8($fp)
	li $t1, 34
	seq $t0, $t0, $t1
	beq $t0, $0, L272
	li $t0, 1
	sw $t0, LA_34
	li $t0, 34
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L271
L272:
	lw $t0, -8($fp)
	li $t1, 35
	seq $t0, $t0, $t1
	beq $t0, $0, L274
	li $t0, 1
	sw $t0, LA_35
	li $t0, 35
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L273
L274:
	lw $t0, -8($fp)
	li $t1, 36
	seq $t0, $t0, $t1
	beq $t0, $0, L276
	li $t0, 1
	sw $t0, LA_36
	li $t0, 36
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L275
L276:
	lw $t0, -8($fp)
	li $t1, 37
	seq $t0, $t0, $t1
	beq $t0, $0, L278
	li $t0, 1
	sw $t0, LA_37
	li $t0, 37
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L277
L278:
	lw $t0, -8($fp)
	li $t1, 38
	seq $t0, $t0, $t1
	beq $t0, $0, L280
	li $t0, 1
	sw $t0, LA_38
	li $t0, 38
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L279
L280:
	lw $t0, -8($fp)
	li $t1, 39
	seq $t0, $t0, $t1
	beq $t0, $0, L282
	li $t0, 1
	sw $t0, LA_39
	li $t0, 39
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L281
L282:
	lw $t0, -8($fp)
	li $t1, 40
	seq $t0, $t0, $t1
	beq $t0, $0, L284
	li $t0, 1
	sw $t0, LA_40
	li $t0, 40
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L283
L284:
	lw $t0, -8($fp)
	li $t1, 41
	seq $t0, $t0, $t1
	beq $t0, $0, L286
	li $t0, 1
	sw $t0, LA_41
	li $t0, 41
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L285
L286:
	lw $t0, -8($fp)
	li $t1, 42
	seq $t0, $t0, $t1
	beq $t0, $0, L288
	li $t0, 1
	sw $t0, LA_42
	li $t0, 42
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L287
L288:
	lw $t0, -8($fp)
	li $t1, 43
	seq $t0, $t0, $t1
	beq $t0, $0, L290
	li $t0, 1
	sw $t0, LA_43
	li $t0, 43
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L289
L290:
	lw $t0, -8($fp)
	li $t1, 44
	seq $t0, $t0, $t1
	beq $t0, $0, L292
	li $t0, 1
	sw $t0, LA_44
	li $t0, 44
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L291
L292:
	lw $t0, -8($fp)
	li $t1, 45
	seq $t0, $t0, $t1
	beq $t0, $0, L294
	li $t0, 1
	sw $t0, LA_45
	li $t0, 45
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L293
L294:
	lw $t0, -8($fp)
	li $t1, 46
	seq $t0, $t0, $t1
	beq $t0, $0, L296
	li $t0, 1
	sw $t0, LA_46
	li $t0, 46
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L295
L296:
	lw $t0, -8($fp)
	li $t1, 47
	seq $t0, $t0, $t1
	beq $t0, $0, L298
	li $t0, 1
	sw $t0, LA_47
	li $t0, 47
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L297
L298:
	lw $t0, -8($fp)
	li $t1, 48
	seq $t0, $t0, $t1
	beq $t0, $0, L300
	li $t0, 1
	sw $t0, LA_48
	li $t0, 48
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L299
L300:
	lw $t0, -8($fp)
	li $t1, 49
	seq $t0, $t0, $t1
	beq $t0, $0, L302
	li $t0, 1
	sw $t0, LA_49
	li $t0, 49
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L301
L302:
	lw $t0, -8($fp)
	li $t1, 50
	seq $t0, $t0, $t1
	beq $t0, $0, L304
	li $t0, 1
	sw $t0, LA_50
	li $t0, 50
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L303
L304:
	lw $t0, -8($fp)
	li $t1, 51
	seq $t0, $t0, $t1
	beq $t0, $0, L306
	li $t0, 1
	sw $t0, LA_51
	li $t0, 51
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L305
L306:
	lw $t0, -8($fp)
	li $t1, 52
	seq $t0, $t0, $t1
	beq $t0, $0, L308
	li $t0, 1
	sw $t0, LA_52
	li $t0, 52
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L307
L308:
	lw $t0, -8($fp)
	li $t1, 53
	seq $t0, $t0, $t1
	beq $t0, $0, L310
	li $t0, 1
	sw $t0, LA_53
	li $t0, 53
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L309
L310:
	lw $t0, -8($fp)
	li $t1, 54
	seq $t0, $t0, $t1
	beq $t0, $0, L312
	li $t0, 1
	sw $t0, LA_54
	li $t0, 54
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L311
L312:
	lw $t0, -8($fp)
	li $t1, 55
	seq $t0, $t0, $t1
	beq $t0, $0, L314
	li $t0, 1
	sw $t0, LA_55
	li $t0, 55
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L313
L314:
	lw $t0, -8($fp)
	li $t1, 56
	seq $t0, $t0, $t1
	beq $t0, $0, L316
	li $t0, 1
	sw $t0, LA_56
	li $t0, 56
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L315
L316:
	lw $t0, -8($fp)
	li $t1, 57
	seq $t0, $t0, $t1
	beq $t0, $0, L318
	li $t0, 1
	sw $t0, LA_57
	li $t0, 57
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L317
L318:
	lw $t0, -8($fp)
	li $t1, 58
	seq $t0, $t0, $t1
	beq $t0, $0, L320
	li $t0, 1
	sw $t0, LA_58
	li $t0, 58
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L319
L320:
	lw $t0, -8($fp)
	li $t1, 59
	seq $t0, $t0, $t1
	beq $t0, $0, L322
	li $t0, 1
	sw $t0, LA_59
	li $t0, 59
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L321
L322:
	lw $t0, -8($fp)
	li $t1, 60
	seq $t0, $t0, $t1
	beq $t0, $0, L324
	li $t0, 1
	sw $t0, LA_60
	li $t0, 60
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L323
L324:
	lw $t0, -8($fp)
	li $t1, 61
	seq $t0, $t0, $t1
	beq $t0, $0, L326
	li $t0, 1
	sw $t0, LA_61
	li $t0, 61
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L325
L326:
	lw $t0, -8($fp)
	li $t1, 62
	seq $t0, $t0, $t1
	beq $t0, $0, L328
	li $t0, 1
	sw $t0, LA_62
	li $t0, 62
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L327
L328:
	lw $t0, -8($fp)
	li $t1, 63
	seq $t0, $t0, $t1
	beq $t0, $0, L330
	li $t0, 1
	sw $t0, LA_63
	li $t0, 63
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L329
L330:
	lw $t0, -8($fp)
	li $t1, 64
	seq $t0, $t0, $t1
	beq $t0, $0, L332
	li $t0, 1
	sw $t0, LA_64
	li $t0, 64
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L331
L332:
	lw $t0, -8($fp)
	li $t1, 65
	seq $t0, $t0, $t1
	beq $t0, $0, L334
	li $t0, 1
	sw $t0, LA_65
	li $t0, 65
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L333
L334:
	lw $t0, -8($fp)
	li $t1, 66
	seq $t0, $t0, $t1
	beq $t0, $0, L336
	li $t0, 1
	sw $t0, LA_66
	li $t0, 66
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L335
L336:
	lw $t0, -8($fp)
	li $t1, 67
	seq $t0, $t0, $t1
	beq $t0, $0, L338
	li $t0, 1
	sw $t0, LA_67
	li $t0, 67
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L337
L338:
	lw $t0, -8($fp)
	li $t1, 68
	seq $t0, $t0, $t1
	beq $t0, $0, L340
	li $t0, 1
	sw $t0, LA_68
	li $t0, 68
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L339
L340:
	lw $t0, -8($fp)
	li $t1, 69
	seq $t0, $t0, $t1
	beq $t0, $0, L342
	li $t0, 1
	sw $t0, LA_69
	li $t0, 69
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L341
L342:
	lw $t0, -8($fp)
	li $t1, 70
	seq $t0, $t0, $t1
	beq $t0, $0, L344
	li $t0, 1
	sw $t0, LA_70
	li $t0, 70
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L343
L344:
	lw $t0, -8($fp)
	li $t1, 71
	seq $t0, $t0, $t1
	beq $t0, $0, L346
	li $t0, 1
	sw $t0, LA_71
	li $t0, 71
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L345
L346:
	lw $t0, -8($fp)
	li $t1, 72
	seq $t0, $t0, $t1
	beq $t0, $0, L348
	li $t0, 1
	sw $t0, LA_72
	li $t0, 72
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L347
L348:
	lw $t0, -8($fp)
	li $t1, 73
	seq $t0, $t0, $t1
	beq $t0, $0, L350
	li $t0, 1
	sw $t0, LA_73
	li $t0, 73
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L349
L350:
	lw $t0, -8($fp)
	li $t1, 74
	seq $t0, $t0, $t1
	beq $t0, $0, L352
	li $t0, 1
	sw $t0, LA_74
	li $t0, 74
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L351
L352:
	lw $t0, -8($fp)
	li $t1, 75
	seq $t0, $t0, $t1
	beq $t0, $0, L354
	li $t0, 1
	sw $t0, LA_75
	li $t0, 75
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L353
L354:
	lw $t0, -8($fp)
	li $t1, 76
	seq $t0, $t0, $t1
	beq $t0, $0, L356
	li $t0, 1
	sw $t0, LA_76
	li $t0, 76
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L355
L356:
	lw $t0, -8($fp)
	li $t1, 77
	seq $t0, $t0, $t1
	beq $t0, $0, L358
	li $t0, 1
	sw $t0, LA_77
	li $t0, 77
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L357
L358:
	lw $t0, -8($fp)
	li $t1, 78
	seq $t0, $t0, $t1
	beq $t0, $0, L360
	li $t0, 1
	sw $t0, LA_78
	li $t0, 78
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L359
L360:
	lw $t0, -8($fp)
	li $t1, 79
	seq $t0, $t0, $t1
	beq $t0, $0, L362
	li $t0, 1
	sw $t0, LA_79
	li $t0, 79
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L361
L362:
	lw $t0, -8($fp)
	li $t1, 80
	seq $t0, $t0, $t1
	beq $t0, $0, L364
	li $t0, 1
	sw $t0, LA_80
	li $t0, 80
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L363
L364:
	lw $t0, -8($fp)
	li $t1, 81
	seq $t0, $t0, $t1
	beq $t0, $0, L366
	li $t0, 1
	sw $t0, LA_81
	li $t0, 81
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L365
L366:
	lw $t0, -8($fp)
	li $t1, 82
	seq $t0, $t0, $t1
	beq $t0, $0, L368
	li $t0, 1
	sw $t0, LA_82
	li $t0, 82
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L367
L368:
	lw $t0, -8($fp)
	li $t1, 83
	seq $t0, $t0, $t1
	beq $t0, $0, L370
	li $t0, 1
	sw $t0, LA_83
	li $t0, 83
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L369
L370:
	lw $t0, -8($fp)
	li $t1, 84
	seq $t0, $t0, $t1
	beq $t0, $0, L372
	li $t0, 1
	sw $t0, LA_84
	li $t0, 84
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L371
L372:
	lw $t0, -8($fp)
	li $t1, 85
	seq $t0, $t0, $t1
	beq $t0, $0, L374
	li $t0, 1
	sw $t0, LA_85
	li $t0, 85
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L373
L374:
	lw $t0, -8($fp)
	li $t1, 86
	seq $t0, $t0, $t1
	beq $t0, $0, L376
	li $t0, 1
	sw $t0, LA_86
	li $t0, 86
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L375
L376:
	lw $t0, -8($fp)
	li $t1, 87
	seq $t0, $t0, $t1
	beq $t0, $0, L378
	li $t0, 1
	sw $t0, LA_87
	li $t0, 87
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L377
L378:
	lw $t0, -8($fp)
	li $t1, 88
	seq $t0, $t0, $t1
	beq $t0, $0, L380
	li $t0, 1
	sw $t0, LA_88
	li $t0, 88
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L379
L380:
	lw $t0, -8($fp)
	li $t1, 89
	seq $t0, $t0, $t1
	beq $t0, $0, L382
	li $t0, 1
	sw $t0, LA_89
	li $t0, 89
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L381
L382:
	lw $t0, -8($fp)
	li $t1, 90
	seq $t0, $t0, $t1
	beq $t0, $0, L384
	li $t0, 1
	sw $t0, LA_90
	li $t0, 90
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L383
L384:
	lw $t0, -8($fp)
	li $t1, 91
	seq $t0, $t0, $t1
	beq $t0, $0, L386
	li $t0, 1
	sw $t0, LA_91
	li $t0, 91
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L385
L386:
	lw $t0, -8($fp)
	li $t1, 92
	seq $t0, $t0, $t1
	beq $t0, $0, L388
	li $t0, 1
	sw $t0, LA_92
	li $t0, 92
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L387
L388:
	lw $t0, -8($fp)
	li $t1, 93
	seq $t0, $t0, $t1
	beq $t0, $0, L390
	li $t0, 1
	sw $t0, LA_93
	li $t0, 93
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L389
L390:
	lw $t0, -8($fp)
	li $t1, 94
	seq $t0, $t0, $t1
	beq $t0, $0, L392
	li $t0, 1
	sw $t0, LA_94
	li $t0, 94
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L391
L392:
	lw $t0, -8($fp)
	li $t1, 95
	seq $t0, $t0, $t1
	beq $t0, $0, L394
	li $t0, 1
	sw $t0, LA_95
	li $t0, 95
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L393
L394:
	lw $t0, -8($fp)
	li $t1, 96
	seq $t0, $t0, $t1
	beq $t0, $0, L396
	li $t0, 1
	sw $t0, LA_96
	li $t0, 96
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L395
L396:
	lw $t0, -8($fp)
	li $t1, 97
	seq $t0, $t0, $t1
	beq $t0, $0, L398
	li $t0, 1
	sw $t0, LA_97
	li $t0, 97
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L397
L398:
	lw $t0, -8($fp)
	li $t1, 98
	seq $t0, $t0, $t1
	beq $t0, $0, L400
	li $t0, 1
	sw $t0, LA_98
	li $t0, 98
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L399
L400:
	lw $t0, -8($fp)
	li $t1, 99
	seq $t0, $t0, $t1
	beq $t0, $0, L402
	li $t0, 1
	sw $t0, LA_99
	li $t0, 99
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
	j L401
L402:
	lw $t0, -8($fp)
	li $t1, 100
	seq $t0, $t0, $t1
	beq $t0, $0, L403
	li $t0, 1
	sw $t0, LA_100
	li $t0, 100
	lw $t1, -4($fp)
	addu $t0, $t0, $t1
	sw $t0, -8($fp)
L403:
L401:
L399:
L397:
L395:
L393:
L391:
L389:
L387:
L385:
L383:
L381:
L379:
L377:
L375:
L373:
L371:
L369:
L367:
L365:
L363:
L361:
L359:
L357:
L355:
L353:
L351:
L349:
L347:
L345:
L343:
L341:
L339:
L337:
L335:
L333:
L331:
L329:
L327:
L325:
L323:
L321:
L319:
L317:
L315:
L313:
L311:
L309:
L307:
L305:
L303:
L301:
L299:
L297:
L295:
L293:
L291:
L289:
L287:
L285:
L283:
L281:
L279:
L277:
L275:
L273:
L271:
L269:
L267:
L265:
L263:
L261:
L259:
L257:
L255:
L253:
L251:
L249:
L247:
L245:
L243:
L241:
L239:
L237:
L235:
L233:
L231:
L229:
L227:
L225:
L223:
L221:
L219:
L217:
L215:
L213:
L211:
L209:
L207:
	j L205
L206:
	lw $t0, -4($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -4($fp)
	j L203
L204:
	li $t0, 1
	sw $t0, -12($fp)
	la $t0, L404
	move $a0, $t0
	jal Lprints
	li $t0, 3
	sw $t0, -4($fp)
L405:
	lw $t0, -4($fp)
	li $t1, 100
	sle $t0, $t0, $t1
	beq $t0, $0, L406
	lw $t0, -4($fp)
	li $t1, 3
	seq $t0, $t0, $t1
	beq $t0, $0, L408
	lw $t0, LA_3
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L409
	li $t0, 3
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L409:
	j L407
L408:
	lw $t0, -4($fp)
	li $t1, 4
	seq $t0, $t0, $t1
	beq $t0, $0, L412
	lw $t0, LA_4
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L413
	li $t0, 4
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L413:
	j L411
L412:
	lw $t0, -4($fp)
	li $t1, 5
	seq $t0, $t0, $t1
	beq $t0, $0, L415
	lw $t0, LA_5
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L416
	li $t0, 5
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L416:
	j L414
L415:
	lw $t0, -4($fp)
	li $t1, 6
	seq $t0, $t0, $t1
	beq $t0, $0, L418
	lw $t0, LA_6
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L419
	li $t0, 6
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L419:
	j L417
L418:
	lw $t0, -4($fp)
	li $t1, 7
	seq $t0, $t0, $t1
	beq $t0, $0, L421
	lw $t0, LA_7
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L422
	li $t0, 7
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L422:
	j L420
L421:
	lw $t0, -4($fp)
	li $t1, 8
	seq $t0, $t0, $t1
	beq $t0, $0, L424
	lw $t0, LA_8
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L425
	li $t0, 8
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L425:
	j L423
L424:
	lw $t0, -4($fp)
	li $t1, 9
	seq $t0, $t0, $t1
	beq $t0, $0, L427
	lw $t0, LA_9
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L428
	li $t0, 9
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L428:
	j L426
L427:
	lw $t0, -4($fp)
	li $t1, 10
	seq $t0, $t0, $t1
	beq $t0, $0, L430
	lw $t0, LA_10
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L431
	li $t0, 10
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L431:
	j L429
L430:
	lw $t0, -4($fp)
	li $t1, 11
	seq $t0, $t0, $t1
	beq $t0, $0, L433
	lw $t0, LA_11
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L434
	li $t0, 11
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L434:
	j L432
L433:
	lw $t0, -4($fp)
	li $t1, 12
	seq $t0, $t0, $t1
	beq $t0, $0, L436
	lw $t0, LA_12
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L437
	li $t0, 12
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L437:
	j L435
L436:
	lw $t0, -4($fp)
	li $t1, 13
	seq $t0, $t0, $t1
	beq $t0, $0, L439
	lw $t0, LA_13
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L440
	li $t0, 13
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L440:
	j L438
L439:
	lw $t0, -4($fp)
	li $t1, 14
	seq $t0, $t0, $t1
	beq $t0, $0, L442
	lw $t0, LA_14
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L443
	li $t0, 14
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L443:
	j L441
L442:
	lw $t0, -4($fp)
	li $t1, 15
	seq $t0, $t0, $t1
	beq $t0, $0, L445
	lw $t0, LA_15
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L446
	li $t0, 15
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L446:
	j L444
L445:
	lw $t0, -4($fp)
	li $t1, 16
	seq $t0, $t0, $t1
	beq $t0, $0, L448
	lw $t0, LA_16
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L449
	li $t0, 16
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L449:
	j L447
L448:
	lw $t0, -4($fp)
	li $t1, 17
	seq $t0, $t0, $t1
	beq $t0, $0, L451
	lw $t0, LA_17
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L452
	li $t0, 17
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L452:
	j L450
L451:
	lw $t0, -4($fp)
	li $t1, 18
	seq $t0, $t0, $t1
	beq $t0, $0, L454
	lw $t0, LA_18
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L455
	li $t0, 18
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L455:
	j L453
L454:
	lw $t0, -4($fp)
	li $t1, 19
	seq $t0, $t0, $t1
	beq $t0, $0, L457
	lw $t0, LA_19
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L458
	li $t0, 19
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L458:
	j L456
L457:
	lw $t0, -4($fp)
	li $t1, 20
	seq $t0, $t0, $t1
	beq $t0, $0, L460
	lw $t0, LA_20
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L461
	li $t0, 20
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L461:
	j L459
L460:
	lw $t0, -4($fp)
	li $t1, 21
	seq $t0, $t0, $t1
	beq $t0, $0, L463
	lw $t0, LA_21
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L464
	li $t0, 21
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L464:
	j L462
L463:
	lw $t0, -4($fp)
	li $t1, 22
	seq $t0, $t0, $t1
	beq $t0, $0, L466
	lw $t0, LA_22
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L467
	li $t0, 22
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L467:
	j L465
L466:
	lw $t0, -4($fp)
	li $t1, 23
	seq $t0, $t0, $t1
	beq $t0, $0, L469
	lw $t0, LA_23
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L470
	li $t0, 23
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L470:
	j L468
L469:
	lw $t0, -4($fp)
	li $t1, 24
	seq $t0, $t0, $t1
	beq $t0, $0, L472
	lw $t0, LA_24
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L473
	li $t0, 24
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L473:
	j L471
L472:
	lw $t0, -4($fp)
	li $t1, 25
	seq $t0, $t0, $t1
	beq $t0, $0, L475
	lw $t0, LA_25
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L476
	li $t0, 25
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L476:
	j L474
L475:
	lw $t0, -4($fp)
	li $t1, 26
	seq $t0, $t0, $t1
	beq $t0, $0, L478
	lw $t0, LA_26
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L479
	li $t0, 26
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L479:
	j L477
L478:
	lw $t0, -4($fp)
	li $t1, 27
	seq $t0, $t0, $t1
	beq $t0, $0, L481
	lw $t0, LA_27
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L482
	li $t0, 27
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L482:
	j L480
L481:
	lw $t0, -4($fp)
	li $t1, 28
	seq $t0, $t0, $t1
	beq $t0, $0, L484
	lw $t0, LA_28
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L485
	li $t0, 28
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L485:
	j L483
L484:
	lw $t0, -4($fp)
	li $t1, 29
	seq $t0, $t0, $t1
	beq $t0, $0, L487
	lw $t0, LA_29
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L488
	li $t0, 29
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L488:
	j L486
L487:
	lw $t0, -4($fp)
	li $t1, 30
	seq $t0, $t0, $t1
	beq $t0, $0, L490
	lw $t0, LA_30
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L491
	li $t0, 30
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L491:
	j L489
L490:
	lw $t0, -4($fp)
	li $t1, 31
	seq $t0, $t0, $t1
	beq $t0, $0, L493
	lw $t0, LA_31
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L494
	li $t0, 31
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L494:
	j L492
L493:
	lw $t0, -4($fp)
	li $t1, 32
	seq $t0, $t0, $t1
	beq $t0, $0, L496
	lw $t0, LA_32
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L497
	li $t0, 32
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L497:
	j L495
L496:
	lw $t0, -4($fp)
	li $t1, 33
	seq $t0, $t0, $t1
	beq $t0, $0, L499
	lw $t0, LA_33
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L500
	li $t0, 33
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L500:
	j L498
L499:
	lw $t0, -4($fp)
	li $t1, 34
	seq $t0, $t0, $t1
	beq $t0, $0, L502
	lw $t0, LA_34
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L503
	li $t0, 34
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L503:
	j L501
L502:
	lw $t0, -4($fp)
	li $t1, 35
	seq $t0, $t0, $t1
	beq $t0, $0, L505
	lw $t0, LA_35
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L506
	li $t0, 35
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L506:
	j L504
L505:
	lw $t0, -4($fp)
	li $t1, 36
	seq $t0, $t0, $t1
	beq $t0, $0, L508
	lw $t0, LA_36
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L509
	li $t0, 36
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L509:
	j L507
L508:
	lw $t0, -4($fp)
	li $t1, 37
	seq $t0, $t0, $t1
	beq $t0, $0, L511
	lw $t0, LA_37
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L512
	li $t0, 37
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L512:
	j L510
L511:
	lw $t0, -4($fp)
	li $t1, 38
	seq $t0, $t0, $t1
	beq $t0, $0, L514
	lw $t0, LA_38
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L515
	li $t0, 38
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L515:
	j L513
L514:
	lw $t0, -4($fp)
	li $t1, 39
	seq $t0, $t0, $t1
	beq $t0, $0, L517
	lw $t0, LA_39
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L518
	li $t0, 39
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L518:
	j L516
L517:
	lw $t0, -4($fp)
	li $t1, 40
	seq $t0, $t0, $t1
	beq $t0, $0, L520
	lw $t0, LA_40
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L521
	li $t0, 40
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L521:
	j L519
L520:
	lw $t0, -4($fp)
	li $t1, 41
	seq $t0, $t0, $t1
	beq $t0, $0, L523
	lw $t0, LA_41
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L524
	li $t0, 41
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L524:
	j L522
L523:
	lw $t0, -4($fp)
	li $t1, 42
	seq $t0, $t0, $t1
	beq $t0, $0, L526
	lw $t0, LA_42
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L527
	li $t0, 42
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L527:
	j L525
L526:
	lw $t0, -4($fp)
	li $t1, 43
	seq $t0, $t0, $t1
	beq $t0, $0, L529
	lw $t0, LA_43
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L530
	li $t0, 43
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L530:
	j L528
L529:
	lw $t0, -4($fp)
	li $t1, 44
	seq $t0, $t0, $t1
	beq $t0, $0, L532
	lw $t0, LA_44
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L533
	li $t0, 44
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L533:
	j L531
L532:
	lw $t0, -4($fp)
	li $t1, 45
	seq $t0, $t0, $t1
	beq $t0, $0, L535
	lw $t0, LA_45
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L536
	li $t0, 45
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L536:
	j L534
L535:
	lw $t0, -4($fp)
	li $t1, 46
	seq $t0, $t0, $t1
	beq $t0, $0, L538
	lw $t0, LA_46
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L539
	li $t0, 46
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L539:
	j L537
L538:
	lw $t0, -4($fp)
	li $t1, 47
	seq $t0, $t0, $t1
	beq $t0, $0, L541
	lw $t0, LA_47
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L542
	li $t0, 47
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L542:
	j L540
L541:
	lw $t0, -4($fp)
	li $t1, 48
	seq $t0, $t0, $t1
	beq $t0, $0, L544
	lw $t0, LA_48
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L545
	li $t0, 48
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L545:
	j L543
L544:
	lw $t0, -4($fp)
	li $t1, 49
	seq $t0, $t0, $t1
	beq $t0, $0, L547
	lw $t0, LA_49
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L548
	li $t0, 49
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L548:
	j L546
L547:
	lw $t0, -4($fp)
	li $t1, 50
	seq $t0, $t0, $t1
	beq $t0, $0, L550
	lw $t0, LA_50
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L551
	li $t0, 50
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L551:
	j L549
L550:
	lw $t0, -4($fp)
	li $t1, 51
	seq $t0, $t0, $t1
	beq $t0, $0, L553
	lw $t0, LA_51
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L554
	li $t0, 51
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L554:
	j L552
L553:
	lw $t0, -4($fp)
	li $t1, 52
	seq $t0, $t0, $t1
	beq $t0, $0, L556
	lw $t0, LA_52
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L557
	li $t0, 52
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L557:
	j L555
L556:
	lw $t0, -4($fp)
	li $t1, 53
	seq $t0, $t0, $t1
	beq $t0, $0, L559
	lw $t0, LA_53
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L560
	li $t0, 53
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L560:
	j L558
L559:
	lw $t0, -4($fp)
	li $t1, 54
	seq $t0, $t0, $t1
	beq $t0, $0, L562
	lw $t0, LA_54
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L563
	li $t0, 54
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L563:
	j L561
L562:
	lw $t0, -4($fp)
	li $t1, 55
	seq $t0, $t0, $t1
	beq $t0, $0, L565
	lw $t0, LA_55
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L566
	li $t0, 55
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L566:
	j L564
L565:
	lw $t0, -4($fp)
	li $t1, 56
	seq $t0, $t0, $t1
	beq $t0, $0, L568
	lw $t0, LA_56
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L569
	li $t0, 56
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L569:
	j L567
L568:
	lw $t0, -4($fp)
	li $t1, 57
	seq $t0, $t0, $t1
	beq $t0, $0, L571
	lw $t0, LA_57
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L572
	li $t0, 57
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L572:
	j L570
L571:
	lw $t0, -4($fp)
	li $t1, 58
	seq $t0, $t0, $t1
	beq $t0, $0, L574
	lw $t0, LA_58
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L575
	li $t0, 58
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L575:
	j L573
L574:
	lw $t0, -4($fp)
	li $t1, 59
	seq $t0, $t0, $t1
	beq $t0, $0, L577
	lw $t0, LA_59
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L578
	li $t0, 59
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L578:
	j L576
L577:
	lw $t0, -4($fp)
	li $t1, 60
	seq $t0, $t0, $t1
	beq $t0, $0, L580
	lw $t0, LA_60
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L581
	li $t0, 60
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L581:
	j L579
L580:
	lw $t0, -4($fp)
	li $t1, 61
	seq $t0, $t0, $t1
	beq $t0, $0, L583
	lw $t0, LA_61
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L584
	li $t0, 61
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L584:
	j L582
L583:
	lw $t0, -4($fp)
	li $t1, 62
	seq $t0, $t0, $t1
	beq $t0, $0, L586
	lw $t0, LA_62
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L587
	li $t0, 62
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L587:
	j L585
L586:
	lw $t0, -4($fp)
	li $t1, 63
	seq $t0, $t0, $t1
	beq $t0, $0, L589
	lw $t0, LA_63
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L590
	li $t0, 63
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L590:
	j L588
L589:
	lw $t0, -4($fp)
	li $t1, 64
	seq $t0, $t0, $t1
	beq $t0, $0, L592
	lw $t0, LA_64
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L593
	li $t0, 64
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L593:
	j L591
L592:
	lw $t0, -4($fp)
	li $t1, 65
	seq $t0, $t0, $t1
	beq $t0, $0, L595
	lw $t0, LA_65
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L596
	li $t0, 65
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L596:
	j L594
L595:
	lw $t0, -4($fp)
	li $t1, 66
	seq $t0, $t0, $t1
	beq $t0, $0, L598
	lw $t0, LA_66
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L599
	li $t0, 66
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L599:
	j L597
L598:
	lw $t0, -4($fp)
	li $t1, 67
	seq $t0, $t0, $t1
	beq $t0, $0, L601
	lw $t0, LA_67
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L602
	li $t0, 67
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L602:
	j L600
L601:
	lw $t0, -4($fp)
	li $t1, 68
	seq $t0, $t0, $t1
	beq $t0, $0, L604
	lw $t0, LA_68
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L605
	li $t0, 68
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L605:
	j L603
L604:
	lw $t0, -4($fp)
	li $t1, 69
	seq $t0, $t0, $t1
	beq $t0, $0, L607
	lw $t0, LA_69
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L608
	li $t0, 69
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L608:
	j L606
L607:
	lw $t0, -4($fp)
	li $t1, 70
	seq $t0, $t0, $t1
	beq $t0, $0, L610
	lw $t0, LA_70
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L611
	li $t0, 70
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L611:
	j L609
L610:
	lw $t0, -4($fp)
	li $t1, 71
	seq $t0, $t0, $t1
	beq $t0, $0, L613
	lw $t0, LA_71
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L614
	li $t0, 71
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L614:
	j L612
L613:
	lw $t0, -4($fp)
	li $t1, 72
	seq $t0, $t0, $t1
	beq $t0, $0, L616
	lw $t0, LA_72
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L617
	li $t0, 72
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L617:
	j L615
L616:
	lw $t0, -4($fp)
	li $t1, 73
	seq $t0, $t0, $t1
	beq $t0, $0, L619
	lw $t0, LA_73
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L620
	li $t0, 73
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L620:
	j L618
L619:
	lw $t0, -4($fp)
	li $t1, 74
	seq $t0, $t0, $t1
	beq $t0, $0, L622
	lw $t0, LA_74
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L623
	li $t0, 74
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L623:
	j L621
L622:
	lw $t0, -4($fp)
	li $t1, 75
	seq $t0, $t0, $t1
	beq $t0, $0, L625
	lw $t0, LA_75
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L626
	li $t0, 75
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L626:
	j L624
L625:
	lw $t0, -4($fp)
	li $t1, 76
	seq $t0, $t0, $t1
	beq $t0, $0, L628
	lw $t0, LA_76
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L629
	li $t0, 76
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L629:
	j L627
L628:
	lw $t0, -4($fp)
	li $t1, 77
	seq $t0, $t0, $t1
	beq $t0, $0, L631
	lw $t0, LA_77
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L632
	li $t0, 77
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L632:
	j L630
L631:
	lw $t0, -4($fp)
	li $t1, 78
	seq $t0, $t0, $t1
	beq $t0, $0, L634
	lw $t0, LA_78
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L635
	li $t0, 78
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L635:
	j L633
L634:
	lw $t0, -4($fp)
	li $t1, 79
	seq $t0, $t0, $t1
	beq $t0, $0, L637
	lw $t0, LA_79
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L638
	li $t0, 79
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L638:
	j L636
L637:
	lw $t0, -4($fp)
	li $t1, 80
	seq $t0, $t0, $t1
	beq $t0, $0, L640
	lw $t0, LA_80
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L641
	li $t0, 80
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L641:
	j L639
L640:
	lw $t0, -4($fp)
	li $t1, 81
	seq $t0, $t0, $t1
	beq $t0, $0, L643
	lw $t0, LA_81
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L644
	li $t0, 81
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L644:
	j L642
L643:
	lw $t0, -4($fp)
	li $t1, 82
	seq $t0, $t0, $t1
	beq $t0, $0, L646
	lw $t0, LA_82
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L647
	li $t0, 82
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L647:
	j L645
L646:
	lw $t0, -4($fp)
	li $t1, 83
	seq $t0, $t0, $t1
	beq $t0, $0, L649
	lw $t0, LA_83
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L650
	li $t0, 83
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L650:
	j L648
L649:
	lw $t0, -4($fp)
	li $t1, 84
	seq $t0, $t0, $t1
	beq $t0, $0, L652
	lw $t0, LA_84
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L653
	li $t0, 84
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L653:
	j L651
L652:
	lw $t0, -4($fp)
	li $t1, 85
	seq $t0, $t0, $t1
	beq $t0, $0, L655
	lw $t0, LA_85
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L656
	li $t0, 85
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L656:
	j L654
L655:
	lw $t0, -4($fp)
	li $t1, 86
	seq $t0, $t0, $t1
	beq $t0, $0, L658
	lw $t0, LA_86
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L659
	li $t0, 86
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L659:
	j L657
L658:
	lw $t0, -4($fp)
	li $t1, 87
	seq $t0, $t0, $t1
	beq $t0, $0, L661
	lw $t0, LA_87
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L662
	li $t0, 87
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L662:
	j L660
L661:
	lw $t0, -4($fp)
	li $t1, 88
	seq $t0, $t0, $t1
	beq $t0, $0, L664
	lw $t0, LA_88
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L665
	li $t0, 88
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L665:
	j L663
L664:
	lw $t0, -4($fp)
	li $t1, 89
	seq $t0, $t0, $t1
	beq $t0, $0, L667
	lw $t0, LA_89
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L668
	li $t0, 89
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L668:
	j L666
L667:
	lw $t0, -4($fp)
	li $t1, 90
	seq $t0, $t0, $t1
	beq $t0, $0, L670
	lw $t0, LA_90
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L671
	li $t0, 90
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L671:
	j L669
L670:
	lw $t0, -4($fp)
	li $t1, 91
	seq $t0, $t0, $t1
	beq $t0, $0, L673
	lw $t0, LA_91
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L674
	li $t0, 91
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L674:
	j L672
L673:
	lw $t0, -4($fp)
	li $t1, 92
	seq $t0, $t0, $t1
	beq $t0, $0, L676
	lw $t0, LA_92
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L677
	li $t0, 92
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L677:
	j L675
L676:
	lw $t0, -4($fp)
	li $t1, 93
	seq $t0, $t0, $t1
	beq $t0, $0, L679
	lw $t0, LA_93
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L680
	li $t0, 93
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L680:
	j L678
L679:
	lw $t0, -4($fp)
	li $t1, 94
	seq $t0, $t0, $t1
	beq $t0, $0, L682
	lw $t0, LA_94
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L683
	li $t0, 94
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L683:
	j L681
L682:
	lw $t0, -4($fp)
	li $t1, 95
	seq $t0, $t0, $t1
	beq $t0, $0, L685
	lw $t0, LA_95
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L686
	li $t0, 95
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L686:
	j L684
L685:
	lw $t0, -4($fp)
	li $t1, 96
	seq $t0, $t0, $t1
	beq $t0, $0, L688
	lw $t0, LA_96
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L689
	li $t0, 96
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L689:
	j L687
L688:
	lw $t0, -4($fp)
	li $t1, 97
	seq $t0, $t0, $t1
	beq $t0, $0, L691
	lw $t0, LA_97
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L692
	li $t0, 97
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L692:
	j L690
L691:
	lw $t0, -4($fp)
	li $t1, 98
	seq $t0, $t0, $t1
	beq $t0, $0, L694
	lw $t0, LA_98
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L695
	li $t0, 98
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L695:
	j L693
L694:
	lw $t0, -4($fp)
	li $t1, 99
	seq $t0, $t0, $t1
	beq $t0, $0, L697
	lw $t0, LA_99
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L698
	li $t0, 99
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L698:
	j L696
L697:
	lw $t0, -4($fp)
	li $t1, 100
	seq $t0, $t0, $t1
	beq $t0, $0, L699
	lw $t0, LA_100
	li $t1, 0
	seq $t0, $t0, $t1
	beq $t0, $0, L700
	li $t0, 100
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
	lw $t0, -12($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -12($fp)
L700:
L699:
L696:
L693:
L690:
L687:
L684:
L681:
L678:
L675:
L672:
L669:
L666:
L663:
L660:
L657:
L654:
L651:
L648:
L645:
L642:
L639:
L636:
L633:
L630:
L627:
L624:
L621:
L618:
L615:
L612:
L609:
L606:
L603:
L600:
L597:
L594:
L591:
L588:
L585:
L582:
L579:
L576:
L573:
L570:
L567:
L564:
L561:
L558:
L555:
L552:
L549:
L546:
L543:
L540:
L537:
L534:
L531:
L528:
L525:
L522:
L519:
L516:
L513:
L510:
L507:
L504:
L501:
L498:
L495:
L492:
L489:
L486:
L483:
L480:
L477:
L474:
L471:
L468:
L465:
L462:
L459:
L456:
L453:
L450:
L447:
L444:
L441:
L438:
L435:
L432:
L429:
L426:
L423:
L420:
L417:
L414:
L411:
L407:
	lw $t0, -4($fp)
	li $t1, 1
	addu $t0, $t0, $t1
	sw $t0, -4($fp)
	j L405
L406:
	lw $t0, -12($fp)
	move $a0, $t0
	jal Lprinti
	la $t0, L701
	move $a0, $t0
	jal Lprints
	li $t0, 100
	move $a0, $t0
	jal Lprinti
	la $t0, L410
	move $a0, $t0
	jal Lprints
L1:
	# epilogue
	addiu $sp, $sp, 12
	lw   $fp, 0($sp)
	lw   $ra, 4($sp)
	addiu $sp, $sp, 8
	jr $ra
LINTERNALseed:
	# prologue
	addiu $sp, $sp, -8
	sw   $ra, 4($sp)
	sw   $fp, 0($sp)
	move $fp, $sp
	addiu $sp, $sp, -4
	sw $a0, -4($fp)
	# body
	lw $t0, -4($fp)
	sw $t0, LINTERNALX
L702:
	# epilogue
	addiu $sp, $sp, 4
	lw   $fp, 0($sp)
	lw   $ra, 4($sp)
	addiu $sp, $sp, 8
	jr $ra
LINTERNALrandom:
	# prologue
	addiu $sp, $sp, -8
	sw   $ra, 4($sp)
	sw   $fp, 0($sp)
	move $fp, $sp
	# body
	li $t0, 17
	lw $t1, LINTERNALX
	mul $t0, $t0, $t1
	li $t1, 13
	addu $t0, $t0, $t1
	li $t1, 32768
	addiu $sp, $sp, -8
	sw $a0, 4($sp)
	sw $a1, ($sp)
	move $a0, $t0
	move $a1, $t1
	jal divModChk
	move $t1, $v0
	lw $a0, 4($sp)
	lw $a1, ($sp)
	addiu $sp, $sp, 8
	rem $t0, $t0, $t1
	sw $t0, LINTERNALX
	lw $t0, LINTERNALX
	# return inst
	move $v0, $t0
	j L703
	# error
	j noReturnError
L703:
	# epilogue
	lw   $fp, 0($sp)
	lw   $ra, 4($sp)
	addiu $sp, $sp, 8
	jr $ra

	.data
LA_0:
	.word 0
LA_1:
	.word 0
LA_2:
	.word 0
LA_3:
	.word 0
LA_4:
	.word 0
LA_5:
	.word 0
LA_6:
	.word 0
LA_7:
	.word 0
LA_8:
	.word 0
LA_9:
	.word 0
LA_10:
	.word 0
LA_11:
	.word 0
LA_12:
	.word 0
LA_13:
	.word 0
LA_14:
	.word 0
LA_15:
	.word 0
LA_16:
	.word 0
LA_17:
	.word 0
LA_18:
	.word 0
LA_19:
	.word 0
LA_20:
	.word 0
LA_21:
	.word 0
LA_22:
	.word 0
LA_23:
	.word 0
LA_24:
	.word 0
LA_25:
	.word 0
LA_26:
	.word 0
LA_27:
	.word 0
LA_28:
	.word 0
LA_29:
	.word 0
LA_30:
	.word 0
LA_31:
	.word 0
LA_32:
	.word 0
LA_33:
	.word 0
LA_34:
	.word 0
LA_35:
	.word 0
LA_36:
	.word 0
LA_37:
	.word 0
LA_38:
	.word 0
LA_39:
	.word 0
LA_40:
	.word 0
LA_41:
	.word 0
LA_42:
	.word 0
LA_43:
	.word 0
LA_44:
	.word 0
LA_45:
	.word 0
LA_46:
	.word 0
LA_47:
	.word 0
LA_48:
	.word 0
LA_49:
	.word 0
LA_50:
	.word 0
LA_51:
	.word 0
LA_52:
	.word 0
LA_53:
	.word 0
LA_54:
	.word 0
LA_55:
	.word 0
LA_56:
	.word 0
LA_57:
	.word 0
LA_58:
	.word 0
LA_59:
	.word 0
LA_60:
	.word 0
LA_61:
	.word 0
LA_62:
	.word 0
LA_63:
	.word 0
LA_64:
	.word 0
LA_65:
	.word 0
LA_66:
	.word 0
LA_67:
	.word 0
LA_68:
	.word 0
LA_69:
	.word 0
LA_70:
	.word 0
LA_71:
	.word 0
LA_72:
	.word 0
LA_73:
	.word 0
LA_74:
	.word 0
LA_75:
	.word 0
LA_76:
	.word 0
LA_77:
	.word 0
LA_78:
	.word 0
LA_79:
	.word 0
LA_80:
	.word 0
LA_81:
	.word 0
LA_82:
	.word 0
LA_83:
	.word 0
LA_84:
	.word 0
LA_85:
	.word 0
LA_86:
	.word 0
LA_87:
	.word 0
LA_88:
	.word 0
LA_89:
	.word 0
LA_90:
	.word 0
LA_91:
	.word 0
LA_92:
	.word 0
LA_93:
	.word 0
LA_94:
	.word 0
LA_95:
	.word 0
LA_96:
	.word 0
LA_97:
	.word 0
LA_98:
	.word 0
LA_99:
	.word 0
LA_100:
	.word 0
Lnot_there:
	.word 0
LINTERNALX:
	.word 0
L410:
	.byte 10
	.byte 0
L701:
	.byte 32
	.byte 112
	.byte 114
	.byte 105
	.byte 109
	.byte 101
	.byte 32
	.byte 110
	.byte 117
	.byte 109
	.byte 98
	.byte 101
	.byte 114
	.byte 115
	.byte 32
	.byte 60
	.byte 61
	.byte 32
	.byte 0
emptyString:
	.byte 0
L404:
	.byte 50
	.byte 10
	.byte 0


# start of RTS
	.data
trueString:
	.asciiz "true"
falseString:
	.asciiz "false"
noReturnErrorString:
	.asciiz "Runtime error: no value returned from function"
divByZeroString:
	.asciiz "Runtime error: division by zero"
input:  .space 2
	.align 4
Ltrue:
	.word 1
Lfalse:
	.word 0

	.text
# $a0 - dividend
# $a1 - divisor
# checking for two things:
# division by 0: runtime error
# right operand = INT_MIN: return $v0 = 1
# we use $v1 here since we know its never used elsewhere
divModChk:
	beq $0, $a1, divByZeroError
    li $v1, -2147483648
    beq $a0, $v1, secondCheck
divModChkDone:
    move $v0, $a1
    jr $ra
secondCheck:
    li $v1, -1
    bne $a1, $v1, divModChkDone
    li $v0, 1
    jr $ra
divByZeroError:
	la $a0, divByZeroString
	jal Lprints
	jal halt
noReturnError:
	la $a0, noReturnErrorString
	jal Lprints
	jal halt
halt:
	li, $v0, 10
	syscall
    jr $ra
# will populate $v0
# literally copy-pasted from Shankar's Tutorial notes "RTS Functions"
# https://pages.cpsc.ucalgary.ca/~sankarasubramanian.g/411/
LgetChar:
    addiu $sp, $sp, -4
    sw $ra, 0($sp)

    li $v0, 8                       # System call for read_string
    la $a0, input                   # Pass in buffer (size = n+1)
    li $a1, 2                       # Size = n+1 as read_string adds null
    syscall

    lb $v0, input
    bne $v0, $zero, ret

    li $v0, -1                      # If 0, map to -1 and return
ret:
    lw $ra 0($sp)
    addiu $sp $sp, 4
    jr $ra

# assumes $a0 is loaded with address of string
Llen:
	# initialize length variable to 0
	addiu $t0, $0, 0
count:
	# load in character at address in $a0
	lb $t1, ($a0)
	# we've reached EOS if the byte == 0
	beq $t1, $0, retLen
	# else we increment length and the address
	addiu $t0, $t0, 1
	addiu $a0, $a0, 1
	j count
retLen:
	# move length to return register and return
	addiu $v0, $t0, 0
	jr $ra

# assumes $a0 is loaded with boolean to print
Lprintb:
	# if the boolean value is 0 then print false
	beq $0 $a0 printFalse
	# else print true
	addiu $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0, trueString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addiu $sp, $sp, 8
	jr $ra
printFalse:
	addiu $sp, $sp, -8
	sw $ra, -4($sp)
	sw $a0, 0($sp)
	la $a0, falseString
	jal Lprints
	lw $a0, 0($sp)
	lw $ra, -4($sp)
	addiu $sp, $sp, 8
	jr $ra

# assume $a0 is loaded with integer to print
Lprintc:
	li $v0 11
	syscall
	jr $ra

# assume $a0 is loaded with integer to print
Lprinti:
	li $v0 1
	syscall
	jr $ra

# assume $a0 is loaded with adress of string to print
Lprints:
	li $v0 4
	syscall
	jr $ra
# end of RTS

