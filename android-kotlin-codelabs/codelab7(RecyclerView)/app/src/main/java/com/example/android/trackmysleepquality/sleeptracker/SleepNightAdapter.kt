package com.example.android.trackmysleepquality.sleeptracker

import android.graphics.Color
import android.util.Log
import android.view.LayoutInflater
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.android.trackmysleepquality.R
import com.example.android.trackmysleepquality.TextItemViewHolder
import com.example.android.trackmysleepquality.database.SleepNight

class SleepNightAdapter: RecyclerView.Adapter<TextItemViewHolder>() {

    // All nights data
    var data = listOf<SleepNight>()
        set(value) {
            field = value
            notifyDataSetChanged()
        }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): TextItemViewHolder {
        Log.i("SleepNightAdapter", "onCreateViewHolder called")
        val layoutInflater = LayoutInflater.from(parent.context)
        val view = layoutInflater.inflate(R.layout.text_item_view, parent, false) as TextView
        return TextItemViewHolder(view)
    }

    override fun getItemCount(): Int {
        return data.size
    }

    override fun onBindViewHolder(holder: TextItemViewHolder, position: Int) {
        Log.i("SleepNightAdapter", "onBindViewHolder called for position $position")
        val item = data[position]
        holder.textView.text = item.sleepQuality.toString()
        if (item.sleepQuality <= 1) {
            holder.textView.setTextColor(Color.RED) // red
        } else {
            // reset
            holder.textView.setTextColor(Color.BLACK) // black
        }
    }
}