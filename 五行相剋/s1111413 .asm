.data
str1: .string " Please enter the strokes of the first last name= "
str2: .string" Please enter the strokes of the second last ,if not,enter 0 ="
str3: .string" Please enter the strokes of the second character of the first name ="
str4: .string" Please enter the strokes of the second character of the second name,if not,enter0 ="
wood: .string " wood"
fire: .string " fire"
earth: .string " earth"
metal: .string  " metal"
water: .string " water"
sky: .string "Sky="
people: .string "People="
land: .string "Land="
outside: .string "Outside="
total: .string "Total="
Sky: .string "Sky"
People: .string "People"
Land: .string "Land"
Outside: .string "Outside"
Total: .string "Total"
name: .string "s1111413"
endl:.string "\n"
array: .word 0:16
array1: .word 0:20
generate_msg: .string " generate "
restraint_msg: .string " restraint "
equal_msg: .string " equal "
.text
main:	
	li t6,0#count
 	la t0, array #array of name
 	la t2,array1#result
 	jal printName
 	jal ENDL
	jal printMsg1
	jal inputM	
	sw a0, 0(t0)# return the result a0
	jal ENDL
	
	jal printMsg2
	jal inputM	
	sw a0, 4(t0)	

	beqz a0,swap
	jal ENDL
		
	
	jal printMsg3
	jal inputM
	sw a0, 8(t0)	
	jal ENDL
			# Set s0 equal to the result
	jal printMsg4
	jal inputM
	sw a0, 12(t0)
	beqz a0,one
	jal ENDL	
			
	jal count
	jal printfive #printResult(a0)	
	jal ENDL
	jal gre
	j end
swap:
    lw a0, 0(t0)   
    addi t6,t6,-1
    li a1,1
    sw a1, 0(t0)     
    sw a0, 4(t0)     
    ret

  
count:
lw a0,0(t0)
lw a1,4(t0)
add a0,a0,a1
sw a0,0(t2)
lw a0,8(t0)
lw a1,4(t0)
add a0,a0,a1
sw a0,4(t2)

lw a0,8(t0)
lw a1,12(t0)
add a0,a0,a1
sw a0,8(t2)

lw a0,0(t0)
lw a1,12(t0)
add a0,a0,a1
sw a0,12(t2)

lw a0,12(t2)
lw a1,4(t2)
add a0,a0,a1
add a0,a0,t6
sw a0,16(t2)
ret
one:
li a0,1
sw a0,12(t0)
addi t6, t6,-1
ret


computeWuXin: 
	mv t1,a0
	li a1, 10
	rem t1, t1, a1

 	
	addi sp,sp,-4
	sw ra,0(sp)
	
	blez t1,ModeWater #12(Wood),34(Fire),56(Earth),78(Metal),90(Water)	
	li a2,2	 
	ble t1,a2,ModeWood
	li a2,4
	ble t1,a2,ModeFire
	li a2,6	 
	ble t1,a2,ModeEarth
	li a2,8
	ble t1,a2,ModeMetal
	li a2,9
	ble t1,a2,ModeWater

endcomputeWuXin: 
	
	lw ra,0(sp)
	addi sp,sp,4
	ret  #return (a0)

ModeWood:
	li t3,2
	la a0,wood
	j endcomputeWuXin
	
ModeFire:
	li t3,4
	la a0,fire
	j endcomputeWuXin

ModeEarth:
	li t3,5
	la a0,earth
	j endcomputeWuXin

ModeMetal:
	li t3,1
	la a0,metal
	j endcomputeWuXin

ModeWater:
	li t3,3
	la a0,water
	j endcomputeWuXin

printfive:
	addi sp,sp,-4
	sw ra,0(sp)
	
	la a0,sky
	li a7, 4			# print string
 	ecall	
 	lw a0,0(t2)
	li a7, 1			# print string
 	ecall
 	lw a0,0(t2)
 	jal computeWuXin
 	li a7, 4			# print string
 	ecall
	la a0, endl			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	sw t3,0(t2)
 	
 	
 	la a0,people
	li a7, 4			# print string
 	ecall
 	lw a0,4(t2)
	li a7, 1			# print string
 	ecall
 	jal computeWuXin
 	li a7, 4			# print string
 	ecall	
 	
 	la a0, endl			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	sw t3,4(t2)
 	
 	la a0,land
	li a7, 4			# print string
 	ecall
 	lw a0,8(t2)
	li a7, 1			# print string
 	ecall
 	jal computeWuXin
 	li a7, 4			# print string
 	ecall	
 	la a0, endl			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	sw t3,8(t2)
 	
 	la a0,outside
	li a7,4		# print string
 	ecall
 	lw a0,12(t2)
	li a7, 1			# print string
 	ecall
 	jal computeWuXin
 	li a7, 4			# print string
 	ecall
	la a0, endl			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	sw t3,12(t2)
 	
 	la a0,total
	li a7, 4			# print string
 	ecall
 	lw a0,16(t2)
	li a7, 1			# print string
 	ecall
 	jal computeWuXin
 	li a7, 4			# print string
 	ecall
 	sw t3,16(t2)
  	lw ra,0(sp)
	addi sp,sp,4
	ret  
 	
inputM:
	li a7,5
	ecall
	ret	
printMsg1:
	la a0, str1			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	ret
 	printMsg2:
	la a0, str2			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	ret
 	printMsg3:
	la a0, str3			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	ret
 	printMsg4:
	la a0, str4			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	ret
 printName:
	la a0, name			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	ret	
  ENDL:
	la a0, endl			# prepare to print string 1
	li a7, 4			# print string
 	ecall
 	ret	
end:
	li a7, 10			
 	ecall
 gre:
addi sp,sp,-12
sw ra,12(sp)
 	lw s0,0(t2)
 	lw s1,4(t2)
 	la t5,Sky
 	la t4,People
 	jal eq
 	jal o
 	
 	lw s0,0(t2)
 	lw s1,8(t2)
 	la t5,Sky
 	la t4,Land
 	jal eq
 	jal o
 	
 	lw s0,0(t2)
 	lw s1,12(t2)
 	la t5,Sky
 	la t4,Outside
	 jal eq
 	jal o
 	
 	lw s0,0(t2)
 	lw s1,16(t2)
 	la t5,Sky
 	la t4,Total
 	jal eq
 	jal o
 	lw s0,4(t2)
 	lw s1,0(t2)
 	la t5,People
 	la t4,Sky
 	jal o
 	lw s0,4(t2)
 	lw s1,8(t2)
 	la t5,People
 	la t4,Land
 	jal eq
 	jal o
 	
 	lw s0,4(t2)
 	lw s1,12(t2)
 	la t5,People
 	la t4,Outside
 	jal o
 	jal eq
 	
 	lw s0,4(t2)
 	lw s1,16(t2)
 	la t5,People
 	la t4,Total
 	jal o
 	jal eq
 	
 	lw s0,8(t2)
 	lw s1,0(t2)
 	la t5,Land
 	la t4,Sky
 	jal o
 	
 	lw s0,8(t2)
 	lw s1,4(t2)
 	la t5,Land
 	la t4,People
 	jal o
 	
 	lw s0,8(t2)
 	lw s1,12(t2)
 	la t5,Land
 	la t4,Outside
 	jal o
 	jal eq
 	
 	lw s0,8(t2)
 	lw s1,16(t2)
 	la t5,Land
 	la t4,Total
 	jal o
 	jal eq
 	
 	lw s0,12(t2)
 	lw s1,0(t2)
 	la t5,Outside
 	la t4,Sky
 	jal o
 	
 	lw s0,12(t2)
 	lw s1,4(t2)
 	la t5,Outside
 	la t4,People
 	jal o
 	
 	lw s0,12(t2)
 	lw s1,8(t2)
 	la t5,Outside
 	la t4,Land
 	jal o
 	
 	lw s0,12(t2)
 	lw s1,16(t2)
 	la t5,Outside
 	la t4,Total
 	jal o
 	jal eq
 	
 	lw s0,16(t2)
 	lw s1,0(t2)
 	la t5,Total
 	la t4,Sky
 	jal o
 	
 	lw s0,16(t2)
 	lw s1,4(t2)
 	la t5,Total
 	la t4,People
 	jal o
 	
 	lw s0,16(t2)
 	lw s1,8(t2)
 	la t5,Total
 	la t4,Land
 	jal o
 	
 	lw s0,16(t2)
 	lw s1,12(t2)
 	la t5,Total
 	la t4,Outside
 	jal o
 	lw ra,12(sp)
jalr zero,0(ra)
o:

li t6,1
beq s0,t6,q1
li t6,2
beq s0,t6,q2
li t6,3
beq s0,t6,q3
li t6,4
beq s0,t6,q4
li t6,5
beq s0,t6,q5
ret

q1:

li t6,3
beq s1,t6,pg
li t6,2
beq s1,t6,pr
ret

q2:

li t6,4
beq s1,t6,pg
li t6,5
beq s1,t6,pr
ret

q3:

li t6,2
beq s1,t6,pg
li t6,4
beq s1,t6,pr

ret

q4:

li t6,5
beq s1,t6,pg
li t6,1
beq s1,t6,pr
ret

q5:

li t6,1
beq s1,t6,pg
li t6,3
beq s1,t6,pr
ret
eq:
sw ra,8(sp)
beq s1,s0,q6
ret
q6:
	lw ra,8(sp)
	mv a0, t5
	li a7, 4			
 	ecall
	la a0, equal_msg		
	li a7, 4			
 	ecall
 	mv a0, t4	
	li a7, 4			
 	ecall
 	la a0, endl	
	li a7, 4			
 	ecall
 	jalr zero,ra,0

 pg:
 sw ra,0(sp)
 	mv a0, t5
	li a7, 4			
 	ecall
	la a0, generate_msg		
	li a7, 4			
 	ecall
 	mv a0, t4	
	li a7, 4			
 	ecall
 	la a0, endl	
	li a7, 4			
 	ecall
ret
 pr:
 		
	mv a0, t5
	li a7, 4			
 	ecall
	la a0, restraint_msg		
	li a7, 4			
 	ecall
 	mv a0, t4	
	li a7, 4			
 	ecall
 	la a0, endl	
	li a7, 4			
 	ecall
 ret